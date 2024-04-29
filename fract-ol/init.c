/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:21:01 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/27 16:41:16 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_position(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	fractol->min_real = -2.0;
	fractol->max_real = 1.5;
	fractol->min_img = -2.0;
	fractol->max_img = 1.5;
	fractol->zoom = 1.0;
	fractol->x_shift = 0.0;
	fractol->y_shift = 0.0;
}

void	init_img(t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->window = NULL;
	fractol->img = NULL;
	fractol->img_addr = NULL;
	fractol->bpp = 0;
	fractol->line_len = 0;
	fractol->endian = 0;
}

void	init_struct(t_fractol *fractol)
{
	init_position(fractol);
	init_img(fractol);
}

void	init_window(t_fractol *fractol)
{
	init_struct(fractol);
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit_fractal(fractol);
	fractol->window = mlx_new_window(fractol->mlx, WIN_W, WIN_H, "Fract-ol");
	if (!fractol->window)
		exit_fractal(fractol);
	fractol->img = mlx_new_image(fractol->mlx, WIN_W, WIN_H);
	fractol->img_addr = mlx_get_data_addr(fractol->img, 
			&fractol->bpp, 
			&fractol->line_len, 
			&fractol->endian);
}
