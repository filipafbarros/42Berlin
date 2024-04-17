/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:12:35 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/17 14:16:11 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Z(n+1) = (Zn)^ 2 + c --> Mandelbrot iteration
// First we initialize the real and imaginary values of the
// complex number Z (zx & zy)
// Then we calculate the corresponding real and imaginary
// parts of the complex number 'c' based on current position

/*
* zoom indicates the zoom lvl
* Offset represents a translation or shift applied to the complex
* plane coordinates. It's used to pan or move the view of the fractal
* without changing its scale. 
*/

void	init_coordenates(t_fractol *fractol)
{
	fractol->z_re = 0.0;
	fractol->z_im = 0.0;
	fractol->c_re = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->c_im = (fractol->y / fractol->zoom) + fractol->offset_y;
}

// void	init_coordenates(t_fractol *fractol)
// {
// 	fractol->z_re = 0.0;
// 	fractol->z_im = 0.0;
// 	fractol->c_re = 
// 	fractol->c_im = 
// }

// void	mandelbrot(t_fractol *fractol)
// {
// 	int			i;
// 	double		z_x;
// 	double		z_y;
// 	int			color;

// 	i = 0;
// 	init_coordenates(fractol);
// 	while (++i < MAX_ITERATIONS)
// 	{
// 		z_x = fractol->z_re * fractol->z_re;
// 		z_y = fractol->z_im * fractol->z_im;
// 		if (z_x + z_y > 4)
// 			break ;
// 		fractol->z_im = 2 * fractol->z_re * fractol->z_im + fractol->c_im;
// 		fractol->z_re = z_x - z_y + fractol->c_re;
// 	}
// 	if (i == MAX_ITERATIONS)
// 		put_pixel(fractol, fractol->x, fractol->y, 0x000000);
// 	else
// 	{
// 		color = 0xFCBE11 + (i % 16) * 1000;
// 		put_pixel(fractol, fractol->x, fractol->y, color + i);
// 	}
// }

void	mandelbrot(t_fractol *fractol)
{
	int			i;
	double		z_x;
	double		z_y;
	int			color;

	i = 0;
	init_coordenates(fractol);
	while (++i < MAX_ITERATIONS)
	{
		z_x = fractol->z_re * fractol->z_re;
		z_y = fractol->z_im * fractol->z_im;
		fractol->z_im = 2 * fractol->z_re * fractol->z_im + fractol->c_im;
		fractol->z_re = z_x - z_y + fractol->c_re;
		if (z_x + z_y > 4)
			break ;
		fractol->z_im = 2 * fractol->z_re * fractol->z_im + fractol->c_im;
		fractol->z_re = z_x - z_y + fractol->c_re;
	}
	if (i == MAX_ITERATIONS)
		put_pixel(fractol, fractol->x, fractol->y, 0x000000);
	else
	{
		color = 0xFCBE11;
		put_pixel(fractol, fractol->x, fractol->y, color);
	}
}


/*
fractol->c_re = (fractol->x - WIN_W / 2) / (0.5 * fractol->zoom * WIN_W) + fractol->offset_x;
fractol->c_im = (fractol->y - WIN_H / 2) / (0.5 * fractol->zoom * WIN_H) + fractol->offset_y;
*/

// 		color = 0xFCBE11 + (i % 16) * 1000;