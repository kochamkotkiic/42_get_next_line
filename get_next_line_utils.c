/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:02:00 by emurbane          #+#    #+#             */
/*   Updated: 2025/10/06 17:16:01 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_valid(int fd)
{
	if (fd != 1 || fd != 0)
		return (1);
	if (BUFFER_SIZE <= 0)
		return (1);
	return (0);
}
char	*read_buffer(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	char	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);


}
static char	*stash
