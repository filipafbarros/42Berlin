/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:35:42 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/20 11:05:43 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG.H
# define SO_LONG.H

# include "minilibx-linux-master/mlx.h"
# include <stdlib.h>

typedef struct s_game
{
	int     fd;
    int     height;
    int     width;
    char    **map;
    
};          t_game


#endif