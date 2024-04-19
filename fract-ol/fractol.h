/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:11:35 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/19 15:03:50 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

// Window
# define WIN_W 800
# define WIN_H 800
# define MAX_ITERATIONS 50

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
	double	zoom;
	double	min_real;
	double	max_real;
	double	min_img;
	double	max_img;
}				t_fractol;

// draw.c
void	put_pixel(t_fractol *frctl, int x, int y, int color);
// void	render_test(t_fractol *fractol);
void	render(t_fractol *fractol, char *query);

// mandelbrot.c
int		mandelbrot(t_fractol *fractol);
int		get_fractal(t_fractol *fractol, char *str);

// utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

// init
void	init_position(t_fractol *fractol);
void	init_img(t_fractol *fractol);
void	init_struct(t_fractol *fractol);
void	init_window(t_fractol *fractol);
void	init_coordenates(t_fractol *fractol);

// main
int		exit_fractal(t_fractol *fractol);


#endif