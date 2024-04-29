/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:07:03 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/26 16:54:08 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
void	zoom(t_fractol *fractol, double zoom)
{
	double	center_re;
	double	center_im;

	center_re = fractol->min_real - fractol->max_real;
	center_im = fractol->max_img - fractol->min_img;
	fractol->max_real = fractol->max_real + (center_re - \
	zoom * center_re) / 2;
	fractol->min_real = fractol->max_real + zoom * center_re;
	fractol->max_img = fractol->min_img + zoom * center_im;
	fractol->min_img = fractol->min_img + (center_im - zoom \
	* center_im) / 2;
}
*/

void	zoom(t_fractol *fractol, double zoom, int x, int y)
{
	double	zoom_value;

	zoom_value = 1.42;
	if (zoom == 1)
	{
		fractol->offset_re = (x / fractol->zoom + fractol->offset_re) - \
			fractol->zoom * zoom_value;
		fractol->offset_im = (y / fractol->zoom + fractol->offset_im) - \
			(fractol->zoom * zoom_value);
		fractol->zoom *= zoom_value;
	}
	else if (zoom == -1)
	{
		fractol->offset_re = (x / fractol->zoom + fractol->offset_re) - \
			fractol->zoom * zoom_value;
		fractol->offset_im = (y / fractol->zoom + fractol->offset_im) - \
			(fractol->zoom * zoom_value);
		fractol->zoom /= zoom_value;
	}
}

// void	move(t_fractol *fractol, char direction, double value)
// {
// 	double	center_re;
// 	double	center_im;

// 	center_re = fractol->min_real - fractol->max_real;
// 	center_im = fractol->max_img - fractol->min_img;
// 	if (direction == 'U')
// 	{
// 		fractol->min_img += center_im * value;
// 		fractol->max_img += center_im * value;
// 	}
// 	else if (direction == 'D')
// 	{
// 		fractol->min_img -= center_im * value;
// 		fractol->max_img -= center_im * value;
// 	}
// 	else if (direction == 'R')
// 	{
// 		fractol->min_real -= center_re * value;
// 		fractol->max_real -= center_re * value;
// 	}
// 	else if (direction == 'L')
// 	{
// 		fractol->min_real += center_re * value;
// 		fractol->max_real += center_re * value;
// 	}
// }
