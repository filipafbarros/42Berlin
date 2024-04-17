/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:11:35 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/17 14:06:08 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>

// Window
# define WIN_W 900
# define WIN_H 900
# define MAX_ITERATIONS 60

// Keys
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364

// Mouse
# define MOUSE_LEFT_CLICK 1
# define MOUSE_RIGHT_CLICK 2
# define MOUSE_WHEEL_BUTTON 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*img_addr;
	int		x;
	int		y;
	int		bpp;
	int		line_len;
	int		endian;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	offset_x;
	double	offset_y;
	double	zoom;
	// double	min_real;
	// double	max_real;
	// double	min_img;
	// double	max_img;
}				t_fractol;

// draw.c
void	put_pixel(t_fractol *frctl, int x, int y, int color);
void	render_mandelbrot(t_fractol *fractol);

// mandelbrot.c
void	mandelbrot(t_fractol *fractol);

// init
void	fractol_init(t_fractol *fractol);
void	init_coordenates(t_fractol *fractol);

// main



#endif