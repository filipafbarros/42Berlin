/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:12:35 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/12 15:52:08 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Z(n+1) = (Zn)^ 2 + c --> Mandelbrot iteration
// First we initialize the real and imaginary values of the
// complex number Z (zx & zy)
// Then we calculate the corresponding real and imaginary
// parts of the complex number 'c' based on current position

/*
* zoom indicates the zoom lvl
* Offset represents a translation or shift applied to the complex
* plane coordinates. It's used to pan or move the view of the fractal
* without changing its scale. 
*/

void	mandelbrot(t_fractol *fractol)
{
	int			i;
	double		zx_temp;

	i = 0;
	fractol->z_re = 0.0;
	fractol->z_im = 0.0;
	fractol->c_re = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->c_im = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (i < MAX_ITERATIONS)
	{
		
	}


}