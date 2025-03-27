/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:26:45 by armarake          #+#    #+#             */
/*   Updated: 2025/03/28 00:57:08 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

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

void	change_position_vertical(t_mlx_data *data, int new_y)
{
	if (data->map->map[new_y][data->player->x_pos]
		&& data->map->map[new_y][data->player->x_pos] == 'E'
		&& data->player->collected == data->map->collectibles_count)
			close_game(data);
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

void	change_position_horizontal(t_mlx_data *data, int new_x)
{
	if (data->map->map[data->player->y_pos][new_x]
		&& data->map->map[data->player->y_pos][new_x] == 'E'
		&& data->player->collected == data->map->collectibles_count)
		close_game(data);
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

void	render_movecount(t_mlx_data *data)
{
	char *count;

	count = ft_itoa(data->player->movements);
	if (!count)
		return ;
	mlx_string_put(data->mlx, data->mlx_win, 10,
		data->map->rows * 64 - 10, 0xFFFFFF, "Movements:");
	mlx_string_put(data->mlx, data->mlx_win, 75,
		data->map->rows * 64 - 10, 0xFFFFFF, count);
	free(count);
}

void	init_data(t_mlx_data *data, t_player *player, t_map *map)
{
	data->map = map;
	data->counter = 0;
	player->collected = 0;
	player->movements = 0;
	data->player = player;
}
