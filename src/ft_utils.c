/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:26:45 by armarake          #+#    #+#             */
/*   Updated: 2025/03/27 19:04:33 by armarake         ###   ########.fr       */
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
		&& data->map->map[new_y][data->player->x_pos] == 'E')
	{
		data->player->collected++;
		close_window(data);
	}
	if (data->map->map[new_y][data->player->x_pos] != '1')
	{
		data->map->map[new_y][data->player->x_pos] = 'P';
		data->map->map[data->player->y_pos][data->player->x_pos] = '0';
		data->player->y_pos = new_y;
	}
}

void	change_position_horizontal(t_mlx_data *data, int new_x)
{
	if (data->map->map[data->player->y_pos][new_x]
		&& data->map->map[data->player->y_pos][new_x] == 'E')
	{
		data->player->collected++;
		close_window(data);
	}
	if (data->map->map[data->player->y_pos][new_x] != '1')
	{
		data->map->map[data->player->y_pos][new_x] = 'P';
		data->map->map[data->player->y_pos][data->player->x_pos] = '0';
		data->player->y_pos = new_x;
	}
}
