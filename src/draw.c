/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:28:40 by armarake          #+#    #+#             */
/*   Updated: 2025/03/30 15:58:51 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_img(t_data *data, int i, int j)
{
	if (data->map->map[i][j] == 'P')
	{
		data->player->x_pos = j;
		data->player->y_pos = i;
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->player_img, j * 64, i * 64);
	}
	else if (data->map->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->wall_img, j * 64, i * 64);
	else if (data->map->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->exit_img, j * 64, i * 64);
	else if (data->map->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->coin_img, j * 64, i * 64);
	else if (data->map->map[i][j] == 'G')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->ghost_img, j * 64, i * 64);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->grass_img, j * 64, i * 64);
}

void	draw_the_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->rows)
	{
		j = 0;
		while (j < data->map->cols)
		{
			put_img(data, i, j);
			j++;
		}
		i++;
	}
}
