/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:24:29 by fibarros          #+#    #+#             */
/*   Updated: 2023/11/22 10:32:25 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	b;

	b = count * size;
	ptr = malloc(b);
	if (!ptr)
		return (NULL);
	else
		ft_memset(ptr, 0, b);
	return (ptr);
}
