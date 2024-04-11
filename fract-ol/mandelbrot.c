/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:12:35 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/10 14:23:40 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Z(n+1) = (Zn)^ 2 + c --> Mandelbrot iteration
// First we initialize the real and imaginary values of the
// complex number Z (zx & zy)
// Then we calculate the corresponding real and imaginary
// parts of the complex number 'c' based on current position

void	mandelbrot(t_fractol *fractol)
{
	int			i;
	double		zx_temp;

	i = 0;
	fractol->zx = 0.0;
	fractol->zy = 0.0;
	fractol->cx = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->cy = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (i < MAX_ITERATIONS)
	{
		
	}


}