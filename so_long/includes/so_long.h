/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:35:42 by fibarros          #+#    #+#             */
/*   Updated: 2024/03/14 15:59:34 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG.h
# define SO_LONG.h

# include "minilibx-linux-master/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct	s_map
{
	char		**map;
	int			height;
	int			width;

}	t_map;

typedef struct s_game
{
	t_map		map;
	void		*mlx_ptr;
	void		*win_ptr;

};          t_game


#endif
