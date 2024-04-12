/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:34:19 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/12 17:10:25 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		pxl = fractol->img_addr + (y * fractol->line_len 
				+ x * (fractol->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}

void	render_fractol(t_fractol *fractol)
{
	
	
	while (fractol->y < WIN_H)
	{
		while(fractol->x < WIN_W)
		{
			
		}
	}

}
