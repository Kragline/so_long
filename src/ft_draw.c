/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:28:40 by armarake          #+#    #+#             */
/*   Updated: 2025/03/27 18:34:26 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

static void	init_textures(t_mlx_data *data)
{
	int	width;
	int	height;

	data->grass_img = mlx_xpm_file_to_image(data->mlx,
			"./img/grass.xpm", &width, &height);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"./img/wall.xpm", &width, &height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			"./img/exit.xpm", &width, &height);
	data->coll_img = mlx_xpm_file_to_image(data->mlx,
			"./img/coin.xpm", &width, &height);
	data->player_img = mlx_xpm_file_to_image(data->mlx,
			"./img/knight.xpm", &width, &height);
}

static void	put_img(t_mlx_data *data, int i, int j)
{
	if (data->map->map[i][j] == 'P')
	{
		data->player->x_pos = j;
		data->player->y_pos = i;
		data->player->collected = 0;
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
			data->coll_img, j * 64, i * 64);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->grass_img, j * 64, i * 64);
}

static void	put_textures(t_mlx_data *data)
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

void	draw_the_map(t_mlx_data *data)
{
	init_textures(data);
	put_textures(data);
}
