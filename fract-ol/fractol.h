/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:11:35 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/27 16:43:15 by fibarros         ###   ########.fr       */
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
	char	*name;
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
	double	k_re;
	double	k_im;
	double	min_real;
	double	max_real;
	double	min_img;
	double	max_img;
	double	zoom;
	double	x_shift;
	double	y_shift;
}				t_fractol;

// draw.c
void	put_pixel(t_fractol *frctl, int x, int y, int color);
int		match_fractal(t_fractol *fractol);
void	render(t_fractol *fractol);

// mandelbrot.c
int		mandelbrot(t_fractol *fractol);
void	get_factal(t_fractol *fractol, char *str);
int		julia(t_fractol *fractol);

// utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
double	ft_atof(char *str);
int		space_sign(char *str, int *is_neg);
void	message(t_fractol *fractol);
int		exit_fractal(t_fractol *fractol);

// init
void	init_position(t_fractol *fractol);
void	init_img(t_fractol *fractol);
void	init_struct(t_fractol *fractol);
void	init_window(t_fractol *fractol);
void	init_coordenates(t_fractol *fractol);

// main
void	get_factal(t_fractol *fractol, char *str);
void	get_julia_values(t_fractol *fractol, int ac, char **av);
void	arg_handler(t_fractol *fractol, int ac, char **av);

// hooks
void	event_management(t_fractol *fractol);
int		mouse_events(int keycode, int x, int y, t_fractol *fractol);
int		key_events(int keycode, t_fractol *fractol);

// colors
int		create_trgb(int t, int r, int g, int b);
int		get_red(int color);
int		get_green(int color);
int		get_blue(int color);
int		get_color(int iterations);

#endif