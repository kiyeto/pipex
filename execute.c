/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:05:38 by abenouda          #+#    #+#             */
/*   Updated: 2021/06/13 16:11:46 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*adapt_path(char **paths, char **args)
{
	char	*res;
	char	*leftover;
	int		fd;

	if (args[0][0] == '/')
		return (args[0]);
	while (*paths)
	{
		leftover = ft_strjoin(*paths++, "/");
		res = ft_strjoin(leftover, args[0]);
		free(leftover);
		fd = open(res, O_RDONLY);
		if (fd > 0)
			return (res);
	}
	return (NULL);
}

int	spawn_proc(char **paths, t_cmd *cmd, char **env)
{
	int		pid;
	char	*binp;

	pid = fork();
	if (!pid)
	{
		if (cmd->input != 0)
		{
			dup2 (cmd->input, 0);
			close (cmd->input);
		}
		if (cmd->output != 1)
		{
			dup2 (cmd->output, 1);
			close (cmd->output);
		}
		binp = adapt_path(paths, cmd->args);
		execve(binp, cmd->args, env);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	return (pid);
}

int	go_ahead(t_pipex *pipex)
{
	int	fd[2];

	pipe(fd);
	pipex->cmd1->output = fd[1];
	pipex->cmd2->input = fd[0];
	spawn_proc(pipex->paths, pipex->cmd1, pipex->env);
	close (fd[1]);
	spawn_proc(pipex->paths, pipex->cmd2, pipex->env);
	return (0);
}

int 	execute(t_pipex *pipex)
{
	int	infd;
	int	outfd;

	infd = open(pipex->infile, O_RDONLY);
	outfd = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (infd < 0 || outfd < 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(errno);
	}
	else
	{
		pipex->cmd1->input = infd;
		pipex->cmd2->output = outfd;
		go_ahead(pipex);
	}
	return (0);
}
