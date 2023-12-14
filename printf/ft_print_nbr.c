/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:51:47 by fibarros          #+#    #+#             */
/*   Updated: 2023/12/14 11:50:54 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int	i;

	i = 1;
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		i++;
	}
	else if (n == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_fd(-(n / 10), 1);
		ft_putchar_fd('8', 1);
		return (11);
	}
	ft_putnbr_fd(n, 1);
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}
