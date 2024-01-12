/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:30:01 by fibarros          #+#    #+#             */
/*   Updated: 2024/01/12 12:12:11 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_read(int fd, char *buff, char *backup)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read >= 1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(backup);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		if (backup == NULL)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

char	*get_line(char *line)
{
	ssize_t		i;
	char		*backup;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	backup = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (backup == NULL)
	{
		free(backup);
		backup = NULL;
	}
	line[i + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = ft_read(fd, buff, backup);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	backup = get_line(line);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

// 	return (0);
// }
