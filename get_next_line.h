/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:44:34 by emurbane          #+#    #+#             */
/*   Updated: 2025/10/13 17:35:31 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char 	*ft_strjoin_free(char *s1, const char *s2);
char	*fill_line_buffer(int fd, char *stash, char *buffer);
char	*set_line(char **stash);
char 	*get_next_line(int fd);


#endif
