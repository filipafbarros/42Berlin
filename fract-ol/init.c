/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:21:01 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/17 14:04:48 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	fractol->zoom = 300;
	fractol->offset_x = -1.21;
	fractol->offset_y = -1.21;
	// fractol->min_real = -2.0;
	// fractol->max_real = 
	// fractol->min_img = 
	// fractol->max_img = 
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, WIN_W, 
			WIN_H, "Filipa 's Fract-ol");
	fractol->img = mlx_new_image(fractol->mlx, WIN_W, WIN_H);
	fractol->img_addr = mlx_get_data_addr(fractol->img, 
			&fractol->bpp, 
			&fractol->line_len, 
			&fractol->endian);
}

/*
void	fractol_init(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	fractol->zoom = 300;
	fractol->offset_x = -1.21;
	fractol->offset_y = -1.21;
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
	{
		ft_printf("Error w/ mxl init");
		exit(EXIT_FAILURE);
	}
	fractol->window = mlx_new_window(fractol->mlx, WIN_W, WIN_H, "My Fract-ol");
	if (!fractol->window)
	{
		ft_printf("Error w/ mxl_window");
		exit(EXIT_FAILURE);
	}
	fractol->img = mlx_new_image(fractol->mlx, WIN_W, WIN_H);
	if (!fractol->img)
	{
		ft_printf("Error w/ mlx_new_image");
		exit(EXIT_FAILURE);
	}
	fractol->img_addr = mlx_get_data_addr(fractol->img, 
			&fractol->bpp, 
			&fractol->line_len, 
			&fractol->endian);
}*/