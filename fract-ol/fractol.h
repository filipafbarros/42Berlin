/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:11:35 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/10 14:41:16 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

// Window
# define WIN_W 900
# define WIN_H 900
# define MAX_ITERATIONS 60

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
	double	cx;
	double	cy;
	double	zx;
	double	zy;
	double	offset_x;
	double	offset_y;
	double	zoom;
}				t_fractol;

#endif