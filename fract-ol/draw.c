/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:34:19 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/25 12:00:40 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		pxl = fractol->img_addr + ((y * fractol->line_len) \
			+ (x * (fractol->bpp / 8)));
		*(unsigned int *)pxl = color;
	}
}

int	match_fractal(t_fractol *fractol)
{
	int	pixel;

	pixel = 0;
	if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
		pixel = mandelbrot(fractol);
	if (ft_strncmp(fractol->name, "julia", 6) == 0)
		pixel = julia(fractol);
	return (pixel);
}

void	render(t_fractol *fractol)
{
	int		pixel;

	mlx_clear_window(fractol->mlx, fractol->window);
	fractol->y = 0;
	while (fractol->y < WIN_H) 
	{
		fractol->x = 0;
		while (fractol->x < WIN_W)
		{
			pixel = match_fractal(fractol);
			if (pixel == MAX_ITERATIONS)
				put_pixel(fractol, fractol->x, fractol->y, 0x000000);
			else
				put_pixel(fractol, fractol->x, fractol->y, \
					get_color(pixel));
			fractol->x++;
		}
		fractol->y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img, 0, 0);
}
