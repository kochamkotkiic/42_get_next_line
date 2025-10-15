/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilka <emilka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:44:34 by emurbane          #+#    #+#             */
/*   Updated: 2025/10/15 20:35:53 by emilka           ###   ########.fr       */
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

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_free(char *s1, char *s2);
char	*create_substring(char *s, unsigned int start, size_t len);
char	*manage_stash(int fd, char **stash, char *buf);
char 	*get_next_line(int fd);


#endif