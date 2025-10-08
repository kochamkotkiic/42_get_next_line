/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:02:00 by emurbane          #+#    #+#             */
/*   Updated: 2025/10/08 19:14:54 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s ++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!(dest) && !(src))
	{
		return (NULL);
	}
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i ++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		count ++;
	}
	return (count);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dup;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len ++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i <= len)
	{
		dup[i] = src[i];
		i ++;
	}
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		sub_len = s_len - start;
	else
		sub_len = len;
	sub = (char *)malloc((sub_len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char *ft_strjoin_free(char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*res;

	if (!s1)
		l1 = 0;
	else
		l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = malloc (l1 + l2 + 1);
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	if (s1)
	{
		ft_memcpy(res, s1, l1);
	}
	ft_memcpy(res + l1, s2, l2);
	res[l1 + l2] = '\0';
	free(s1);
	return (res);
}

int	is_valid(int fd)
{
	if (fd < 0)
		return (1);
	if (BUFFER_SIZE <= 0)
		return (1);
	return (0);
}
char	*fill_line_buffer(int fd, char *stash, char *buffer)
{
	int	bytes;

	while (!ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(stash);
			return (NULL);
		}
		if (bytes == 0)
			break;
		buffer[bytes] = '\0';
		stash = ft_strjoin_free(stash, buffer);
		if (!stash)
			return NULL;
	}
	return (stash);
}

char	*set_line(char **stash)
{
	char	*line;
	char	*rest;
	size_t	i;

	i = 0;
	if (!stash || !*stash)
		return (NULL);
	while ((*stash)[i] && (*stash)[i] != '\n')
        i++;
	if ((*stash[i]) == '\n')
	{
		line = ft_substr(*stash, 0 , i + 1);
		rest = ft_substr(*stash, i + 1, ft_strlen(*stash) - (i + 1));
		free(*stash);
		if (rest && *rest != '\0')
			*stash = rest;
		else
		{
			free(rest);
			*stash = NULL;
		}
		return (line);
	}
	line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

char 	*get_next_line(int fd)
{
	static char	*stash;
	char	*buffer;
	char	*line;

	if (is_valid(fd) == 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = fill_line_buffer(fd, stash, buffer);
	free(buffer);
	if (!stash)
		return (NULL);
	line = set_line(&stash);
	return (line);
}
