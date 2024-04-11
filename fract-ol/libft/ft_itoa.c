/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:04:10 by fibarros          #+#    #+#             */
/*   Updated: 2023/11/29 18:14:29 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(long num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	len;
	char	*str;
	long	num;

	num = n;
	len = ft_count_digits(n);
	if (n < 0)
		num *= -1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (num == 0)
		str[0] = '0';
	else
	{
		while (len--, num != 0)
		{
			str[len] = (num % 10) + '0';
			num = (num - (num % 10)) / 10;
		}
		if (n < 0)
			str[len] = '-';
	}
	return (str);
}
