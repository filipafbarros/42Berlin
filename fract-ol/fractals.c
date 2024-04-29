/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:12:35 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/27 16:54:56 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_coordenates(t_fractol *fractol)
{
	fractol->z_re = 0.0;
	fractol->z_im = 0.0;
	fractol->c_re = 0.0;
	fractol->c_im = 0.0;
}

int	mandelbrot(t_fractol *fractol)
{
	int			i;
	double		z_x;
	double		z_y;
	double		temp;

	i = 0;
	init_coordenates(fractol);
	fractol->c_re = (fractol->min_real + (double)fractol->x * (fractol->max_img \
		- fractol->min_real) / WIN_W) * fractol->zoom + fractol->x_shift;
	fractol->c_im = (fractol->max_img + (double)fractol->y * (fractol->min_img \
		- fractol->max_img) / WIN_H) * fractol->zoom + fractol->y_shift;
	while (i < MAX_ITERATIONS)
	{
		z_x = fractol->z_re * fractol->z_re;
		z_y = fractol->z_im * fractol->z_im;
		if (z_x + z_y > 4)
			break ;
		temp = 2 * fractol->z_re * fractol->z_im + fractol->c_im;
		fractol->z_re = z_x - z_y + fractol->c_re;
		fractol->z_im = temp;
		i++;
	}
	return (i);
}

int	julia(t_fractol *fractol)
{
	int			i;
	double		temp;

	i = 0;
	init_coordenates(fractol);
	fractol->z_re = (fractol->min_real + (double)fractol->x * (fractol->max_img \
		- fractol->min_real) / WIN_W) * fractol->zoom + fractol->x_shift;
	fractol->z_im = (fractol->max_img + (double)fractol->y * (fractol->min_img \
		- fractol->max_img) / WIN_H) * fractol->zoom + fractol->y_shift;
	while (i < MAX_ITERATIONS)
	{
		temp = fractol->z_re;
		fractol->z_re = fractol->z_re * fractol->z_re - fractol->z_im * \
			fractol->z_im + fractol->k_re;
		fractol->z_im = 2 * fractol->z_im * temp + fractol->k_im;
		if (fractol->z_re * fractol->z_re + fractol->z_im * fractol->z_im >= 4)
			break ;
		i++;
	}
	return (i);
}
