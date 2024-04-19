/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:34:19 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/19 12:38:51 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		pxl = fractol->img_addr + ((y * fractol->line_len) + (x * (fractol->bpp / 8)));
		*(unsigned int *)pxl = color;
	}
}

int	get_fractal(t_fractol *fractol, char *str)
{
	int	pixel;

	if (ft_strncmp(str, "mandelbrot", 10) == 0)
		pixel = mandelbrot(fractol);
	// else if (ft_strncmp(str, "julia", 6) == 0)
	// 	pixel = julia(fractol);
	else
	{
		ft_putstr_fd("Available fractals: mandelbrot, julia \n", 1);
		exit_fractal(fractol);
		return (0);
	}
	return (pixel);
}


void	render(t_fractol *fractol, char *query)
{
	int		pixel;

	mlx_clear_window(fractol->mlx, fractol->window);
	fractol->y = 0;
	while (fractol->y < WIN_H) 
	{
		fractol->x = 0;
		while (fractol->x < WIN_W)
		{
			pixel = get_fractal(fractol, query);
			if (pixel == MAX_ITERATIONS)
				put_pixel(fractol, fractol->x, fractol->y, 0xFCBE11);
			else
				put_pixel(fractol, fractol->x, fractol->y, 0x000000);
			fractol->x++;
		}
		fractol->y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img, 0, 0);
}
