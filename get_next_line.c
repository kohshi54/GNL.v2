/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:13:58 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/04/15 03:14:16 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*save;
	size_t		byte_to_nl;
	size_t		byte_to_end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(save, '\n') && my_read(fd, buf, &save))
	{
		save = ft_strjoin(save, buf);
		if (!save)
			return (NULL);
	}
	byte_to_nl = ft_strchr(save, '\n');
	byte_to_end = ft_strchr(save, '\0');
	line = get_line(save, byte_to_nl, byte_to_end);
	if (!line)
		return (NULL);
	save = update_save(save, &line, byte_to_nl, byte_to_end);
	return (line);
}
