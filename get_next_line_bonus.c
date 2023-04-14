/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:38:29 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/04/15 03:41:25 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*save[OPEN_MAX];
	size_t		byte_to_nl;
	size_t		byte_to_end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(save[fd], '\n') && my_read(fd, buf, &save[fd]))
	{
		save[fd] = ft_strjoin(save[fd], buf);
		if (!save[fd])
			return (NULL);
	}
	byte_to_nl = ft_strchr(save[fd], '\n');
	byte_to_end = ft_strchr(save[fd], '\0');
	line = get_line(save[fd], byte_to_nl, byte_to_end);
	if (!line)
		return (NULL);
	save[fd] = update_save(save[fd], &line, byte_to_nl, byte_to_end);
	return (line);
}
