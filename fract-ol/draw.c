/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:34:19 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/17 14:33:58 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		pxl = fractol->img_addr + (y * fractol->line_len + x * (fractol->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}

void	render_mandelbrot(t_fractol *fractol)
{
	fractol->y = 0;
	while (fractol->y < WIN_H)
	{
		fractol->x = 0;
		while (fractol->x < WIN_W)
		{
			mandelbrot(fractol);
			fractol->x++;
		}
		fractol->y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img_addr, 0, 0);
}

// add exit fractal functin to 