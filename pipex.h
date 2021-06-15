/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:50:10 by abenouda          #+#    #+#             */
/*   Updated: 2021/06/13 15:48:50 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_cmd
{
	char		**args;
	int			input;
	int			output;
}				t_cmd;

typedef struct s_pipex
{
	t_cmd		*cmd1;
	t_cmd		*cmd2;
	char		*infile;
	char		*outfile;
	char		**paths;
	char		**env;
}				t_pipex;

size_t			ft_strlen(const char *str);
char			*ft_strrchr(const char *s, int c);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr_fd(char *s, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
t_cmd			*new_cmd(char *arg);
int				execute(t_pipex *pipex);

#endif