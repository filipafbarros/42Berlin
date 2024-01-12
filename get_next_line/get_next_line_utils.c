/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:30:16 by fibarros          #+#    #+#             */
/*   Updated: 2024/01/12 11:46:48 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(*src) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if ((int)start > ft_strlen(str))
		return (ft_strdup(""));
	if (ft_strlen(str) - start < len)
		len = ft_strlen(str) - start;
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	while (i < len && str[start])
		new[i++] = str[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	i = 0;
	find = (unsigned char)c;
	while (s[i] != find)
	{
		if (s[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)s + i);
}
