/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:29:00 by fibarros          #+#    #+#             */
/*   Updated: 2023/12/12 15:15:31 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	ft_print_hex(unsigned int num, const char format);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_str(char *s);
int	ft_print_u(unsigned int nb);
int	ft_print_nbr(int n);

#endif
