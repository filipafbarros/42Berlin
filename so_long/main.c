/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:42:23 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/19 11:46:17 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MALLOC_ERROR	1
#define WIDTH			400
#define HEIGHT			400

int	main(void)
{
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	if (!mlx_connection)
		return (MALLOC_ERROR);
	// Window
	mlx_window = mlx_new_window(mlx_connection, mlx_ptr: 
								HEIGHT, size_x: 
								WIDTH, size_y: 
								"My window"); title:
	if (mlx_window == NULL)
	{
		mlx_destroy_display(mlx_connection); mlx_ptr:
		free(mlx_connection); ptr:
		return (MALLOC_ERROR);
	}
	mlx_loop(mlx_connection);
	mlx_destroy_window(mlx_connection, mlx_window); mlx_ptr: win_ptr:
	mlx_destroy_display(mlx_connection); mlx_ptr:
	free(mlx_connection); ptr:
	return (0);
}

// mlx_destroy_display ?

