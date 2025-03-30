/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:03 by armarake          #+#    #+#             */
/*   Updated: 2025/03/30 17:13:26 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_data		data;
	t_map		map;
	t_player	player;
	t_coin		coin;
	t_ghost		ghost;

	if (argc != 2)
		throw_an_error("Usage: ./so_long mapfile", NULL);
	data = init_data(&map, &player, &coin, &ghost);
	validate_and_allocate(argv[1], &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		throw_an_error("Failed to initialize mlx", &data);
	data.mlx_win = mlx_new_window(data.mlx, 64 * data.map->cols,
			64 * data.map->rows, "So long");
	if (!data.mlx_win)
		throw_an_error("Failed to create the window", &data);
	init_textures(&data);
	mlx_key_hook(data.mlx_win, handle_key_press, &data);
	mlx_hook(data.mlx_win, 17, 0, close_game, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
