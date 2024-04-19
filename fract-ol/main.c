/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:54:14 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/19 15:16:48 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	exit_fractal(t_fractol *fractol)
{
	if (fractol->img)
		mlx_destroy_image(fractol->mlx, fractol->img_addr);
	if (fractol->window)
		mlx_destroy_window(fractol->mlx, fractol->window);
	if (fractol->mlx)
		mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	free(fractol);
	exit(0);
}

// void	render_test(t_fractol *fractol)
// {
// 	// fractol->y = 0;
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


int	main(int ac, char **av)
{
	t_fractol	*fractol;

	if (ac < 2)
	{
		ft_putstr_fd("Invalid usage, please use the following way: ./fractol <fractal> \n", 1);
		ft_putstr_fd("Please choose a fractal: mandelbrot, julia \n", 1);
		return (0);
	}
	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		return (1);
	init_window(fractol);
	// render_test(fractol);
	render(fractol, av[1]);
	mlx_loop(fractol->mlx);
	return (0);
}
