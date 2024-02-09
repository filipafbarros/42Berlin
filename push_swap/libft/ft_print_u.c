/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:40:06 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/05 10:45:05 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_u(unsigned int n)
{
	if (n >= 10)
	{
		put_u(n / 10);
		put_u(n % 10);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

int	ft_print_u(unsigned int nb)
{
	unsigned int	i;

	put_u(nb);
	i = 1;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
