/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:48:02 by abenouda          #+#    #+#             */
/*   Updated: 2021/06/13 15:49:31 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (ft_strrchr(env[i], '=') + 1);
	return (NULL);
}

void	fill(t_pipex *p, char **args, char *paths, char **env)
{
	p->infile = args[1];
	p->cmd1 = new_cmd(args[2]);
	p->cmd2 = new_cmd(args[3]);
	p->outfile = args[4];
	p->paths = ft_split(paths, ':');
	p->env = env;
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		printf("Arguments error\n");
	else
	{
		if (!get_path(env))
		{
			printf("PATH is not set\n");
			exit(-1);
		}
		fill(&pipex, argv, get_path(env), env);
		execute(&pipex);
	}
	exit(0);
}
