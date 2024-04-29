/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:12:38 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/27 16:53:29 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_events(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
	{
		exit_fractal(fractol);
		return (0);
	}
	else if (keycode == KEY_UP)
		fractol->y_shift += 0.05 * fractol->zoom;
	else if (keycode == KEY_DOWN)
		fractol->y_shift -= 0.05 * fractol->zoom;
	else if (keycode == KEY_RIGHT)
		fractol->x_shift += 0.05 * fractol->zoom;
	else if (keycode == KEY_LEFT)
		fractol->x_shift -= 0.05 * fractol->zoom;
	render(fractol);
	return (0);
}

int	mouse_events(int keycode, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_WHEEL_UP)
		fractol->zoom *= 1.05;
	else if (keycode == MOUSE_WHEEL_DOWN)
		fractol->zoom *= 0.95;
	else
		return (0);
	render(fractol);
	return (0);
}

void	event_management(t_fractol *fractol)
{
	mlx_mouse_hook(fractol->window, mouse_events, fractol);
	mlx_key_hook(fractol->window, key_events, fractol);
	mlx_hook(fractol->window, 17, 0, exit_fractal, fractol);
}
