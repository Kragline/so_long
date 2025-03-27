/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:57:35 by armarake          #+#    #+#             */
/*   Updated: 2025/03/28 00:48:07 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

static int	render_next_frame(t_mlx_data *data)
{
	if (!data)
		return (0);
	data->counter++;
	if (data->counter >= 4000)
	{
		draw_the_map(data);
		render_movecount(data);
		data->counter = 0;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_mlx_data	data;
	t_player	player;
	t_map		map;

	if (argc != 2)
		throw_an_error("Usage: ./so_long mapfile", NULL);
	validate_and_allocate(argv[1], &map);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 64 * map.cols,
			64 * map.rows, "So long");
	init_data(&data, &player, &map);
	mlx_key_hook(data.mlx_win, handle_key_press, &data);
	mlx_hook(data.mlx_win, 17, 0, close_game, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
