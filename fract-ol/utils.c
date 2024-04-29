/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:26:56 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/29 10:21:37 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && i < n)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		i++;
	}
	if (i == n)
	{
		--s1;
		--s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	exit_fractal(t_fractol *fractol)
{
	if (fractol == NULL)
		return (0);
	if (fractol->img)
		mlx_destroy_image(fractol->mlx, fractol->img);
	if (fractol->window)
		mlx_destroy_window(fractol->mlx, fractol->window);
	if (fractol->mlx)
	{
		mlx_loop_end(fractol->mlx);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	free(fractol);
	exit(0);
}

void	message(t_fractol *fractol)
{
	ft_putstr_fd("Invalid usage, please use: ./fractol <fractal> \n", 2);
	ft_putstr_fd("Please choose a fractal: mandelbrot, julia \n", 2);
	exit_fractal(fractol);
}
