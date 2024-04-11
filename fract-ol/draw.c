/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:34:19 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/10 15:50:46 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *frctl, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		pxl = frctl->img_addr + (y * frctl->line_len + x * (frctl->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}

void    render_fractol(t_fractol *fractol)
{
    fractol_init(fractol);
    
}