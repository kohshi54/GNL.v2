/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:14:10 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/04/15 03:16:47 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	my_read(int fd, char *buf, char **save);
char	*get_line(char *save, size_t byte_to_nl, size_t byte_to_end);
char	*update_save(char *save, char **line, size_t byte_to_nl, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
