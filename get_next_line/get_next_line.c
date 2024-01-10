/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:30:01 by fibarros          #+#    #+#             */
/*   Updated: 2024/01/10 10:34:11 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	ft_read(int fd, char *buff, char *backup)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		if (!backup)
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
	static int	count;
	char		*backup;

	count = 0;
	/*find a newline or end of string*/
	while (line[count] != '\n' || line[count] != '\0')
		count++;
	/*Check if end of string*/
	if (line[count] == '\0' || line[1] == '\0')
		return (0);



}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*backup;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
}

int	main(void)
{
	
}