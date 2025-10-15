/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilka <emilka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:02:00 by emurbane          #+#    #+#             */
/*   Updated: 2025/10/15 20:32:30 by emilka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*create_substring(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*manage_stash(int fd, char **stash, char *buf)
{
	int		bytes;
	size_t	i;
	char	*line;
	char	*rest;

	bytes = 1;
	while (bytes > 0 && (!*stash || !ft_strchr(*stash, '\n')) && (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		*stash = ft_strjoin_free(*stash, buf);
	}
	if (bytes < 0 || !*stash || **stash == '\0')
		return (free(*stash), *stash = NULL, NULL);
	i = -1;
	while ((*stash)[++i] && (*stash)[i] != '\n')
		;
	line = create_substring(*stash, 0, i + ((*stash)[i] == '\n'));
	rest = create_substring(*stash, i + 1, ft_strlen(*stash) - i);
	free(*stash);
	if ((*stash = rest) && !*rest)
		(free(rest), *stash = NULL);
	return (line);
}
