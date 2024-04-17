/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:54:14 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/17 14:37:07 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	exit_fractal(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img_addr);
	mlx_destroy_window(fractol->mlx, fractol->window);
	free(fractol->mlx);
	free(fractol);
	exit(1);
	return (0);
}

// void	render_test(t_fractol *fractol)
// {
// 	while (fractol->y < WIN_H)
// 	{
// 		fractol->x = 0;
// 		while (fractol->x < WIN_W)
// 		{
// 			put_pixel(fractol, fractol->x, fractol->y, 0xFCBE11);
// 			fractol->x++;
// 		}
// 		fractol->y++;
// 	}
// 	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img, 0, 0);
// }


int	main(void)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		return (1);
	fractol_init(fractol);
	// render_test(fractol);
	render_mandelbrot(fractol);
	mlx_loop(fractol->mlx);
}



/*
mlx_hook
mlx_key hook
mlx_mouse hook
*/