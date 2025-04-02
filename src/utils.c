/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:34:56 by armarake          #+#    #+#             */
/*   Updated: 2025/04/02 15:11:54 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_starting_position(t_map *map, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'P')
			{
				*start_x = i;
				*start_y = j;
				break ;
			}
			j++;
		}
		i++;
		if (*start_x != -1)
			break ;
	}
}

void	change_position_vertical(t_data *data, int new_y)
{
	if (data->map->map[new_y][data->player->x_pos]
		&& data->map->map[new_y][data->player->x_pos] == 'G')
		game_over(data, 0);
	if (data->map->map[new_y][data->player->x_pos]
		&& data->map->map[new_y][data->player->x_pos] == 'E'
		&& data->player->collected == data->map->coin_count)
		game_over(data, 1);
	if (data->map->map[new_y][data->player->x_pos]
		&& data->map->map[new_y][data->player->x_pos] != 'E'
		&& data->map->map[new_y][data->player->x_pos] != '1')
	{
		if (data->map->map[new_y][data->player->x_pos] == 'C')
			data->player->collected++;
		data->map->map[new_y][data->player->x_pos] = 'P';
		data->map->map[data->player->y_pos][data->player->x_pos] = '0';
		data->player->y_pos = new_y;
		data->player->movements++;
	}
}

void	change_position_horizontal(t_data *data, int new_x)
{
	if (data->map->map[data->player->y_pos][new_x]
		&& data->map->map[data->player->y_pos][new_x] == 'G')
		game_over(data, 0);
	if (data->map->map[data->player->y_pos][new_x]
		&& data->map->map[data->player->y_pos][new_x] == 'E'
		&& data->player->collected == data->map->coin_count)
		game_over(data, 1);
	if (data->map->map[data->player->y_pos][new_x]
		&& data->map->map[data->player->y_pos][new_x] != 'E'
		&& data->map->map[data->player->y_pos][new_x] != '1')
	{
		if (data->map->map[data->player->y_pos][new_x] == 'C')
			data->player->collected++;
		data->map->map[data->player->y_pos][new_x] = 'P';
		data->map->map[data->player->y_pos][data->player->x_pos] = '0';
		data->player->y_pos = new_x;
		data->player->movements++;
	}
}

t_data	init_data(t_map *map, t_player *player, t_coin *coin, t_ghost *ghost)
{
	t_data	data;

	data.mlx = NULL;
	data.mlx_win = NULL;
	data.grass_img = NULL;
	data.wall_img = NULL;
	data.exit_img = NULL;
	data.player_img = NULL;
	data.counter = 0;
	data.map = map;
	player->collected = 0;
	player->movements = 0;
	data.player = player;
	coin->index = 0;
	data.coin = coin;
	ghost->index = 0;
	ghost->direction = 1;
	data.ghost = ghost;
	return (data);
}
