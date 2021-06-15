/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:12:56 by abenouda          #+#    #+#             */
/*   Updated: 2021/06/13 15:39:07 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*joinstr;

	len = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joinstr = (char *)malloc(len + 1);
	if (!joinstr)
		return (NULL);
	while (s1[i] != 0)
		joinstr[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		joinstr[j++] = s2[i++];
	joinstr[j] = '\0';
	return (joinstr);
}
