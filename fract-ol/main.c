/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:54:14 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/29 10:20:35 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_factal(t_fractol *fractol, char *str)
{
	if (ft_strncmp(str, "mandelbrot", 10) == 0)
		fractol->name = "mandelbrot";
	else if (ft_strncmp(str, "julia", 6) == 0)
		fractol->name = "julia";
	else
	{
		message(fractol);
		return ;
	}
}

void	get_julia_values(t_fractol *fractol, int ac, char **av)
{
	if (ft_strncmp(fractol->name, "julia", 6) != 0 || ac == 2)
	{
		fractol->k_re = -0.766667;
		fractol->k_im = -0.090000;
		return ;
	}
	if (ac == 3)
		message(fractol);
	fractol->k_re = ft_atof(av[2]);
	fractol->k_im = ft_atof(av[3]);
	if (fractol->k_re > 2.0 || fractol->k_re < -2.0)
		message(fractol);
	if (fractol->k_im > 2.0 || fractol->k_im < -2.0)
		message(fractol);
}

void	arg_handler(t_fractol *fractol, int ac, char **av)
{
	get_factal(fractol, av[1]);
	if ((ft_strncmp(fractol->name, "mandelbrot", 10) == 0) && ac > 2)
		message(fractol);
	else if ((ft_strncmp(fractol->name, "julia", 6) != 0) && ac > 3)
		message(fractol);
	else if (ft_strncmp(fractol->name, "julia", 6) == 0 && ac > 5)
		message(fractol);
	get_julia_values(fractol, ac, av);
}

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	if (ac < 2)
	{
		ft_putstr_fd("Invalid usage, please use: ./fractol <fractal> \n", 2);
		ft_putstr_fd("Please choose a fractal: mandelbrot, julia \n", 2);
		return (0);
	}
	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		return (1);
	arg_handler(fractol, ac, av);
	init_window(fractol);
	render(fractol);
	event_management(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
