/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:21:01 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/10 12:34:27 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
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
	fractol->img_address = mlx_get_data_addr(fractol->img, 
			&fractol->bits_per_pixel, 
			&fractol->line_length, 
			&fractol->endian);
}