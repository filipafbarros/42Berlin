/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:30:25 by fibarros          #+#    #+#             */
/*   Updated: 2024/01/12 11:46:33 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*get_line(char *line);
static char	*ft_read(int fd, char *buff, char *backup);

char		*ft_strdup(char *src);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_substr(const char *str, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);

#endif
