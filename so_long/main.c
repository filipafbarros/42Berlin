/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:42:23 by fibarros          #+#    #+#             */
/*   Updated: 2024/03/14 15:27:18 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// #define MALLOC_ERROR	1
// #define WIDTH			400
// #define HEIGHT			400

// int	main(void)
// {
// 	void	*mlx_connection;
// 	void	*mlx_window;

// 	mlx_connection = mlx_init();
// 	if (!mlx_connection)
// 		return (MALLOC_ERROR);
// 	// Window
// 	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "my map");
// 	if (mlx_window == NULL)
// 	{
// 		mlx_destroy_display(mlx_connection);
// 		free(mlx_connection);
// 		return (MALLOC_ERROR);
// 	}
// 	mlx_loop(mlx_connection);
// 	mlx_destroy_window(mlx_connection, mlx_window); mlx_ptr: win_ptr:
// 	mlx_destroy_display(mlx_connection); mlx_ptr:
// 	free(mlx_connection); ptr:
// 	return (0);
// }

// mlx_destroy_display ?

static void	args_check(int ac, char **av)
{
	if (argc != 2)
}

int	main(int ac, char **av)
{
	t_game	game;

	args_check(ac, av);
	// Init game
	// get map
	// check map
	// render map
	// play
}
