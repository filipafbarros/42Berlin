/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:54:14 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/10 14:38:49 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		pxl = fractol->img_address + (y * fractol->line_length + x * (fractol->bits / 8));
		*(unsigned int *)pxl = color;
	}
}

int main(int ac, char **av)
{
	t_fractol	*fractol;
	// put_pixel(&img, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0xFF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(fractol->mlx);
}
