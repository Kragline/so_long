/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:28:40 by armarake          #+#    #+#             */
/*   Updated: 2025/03/29 19:39:19 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

static void	init_player_textures(t_mlx_data *data)
{
	int	width;
	int	height;

	data->player->player_images[0] = mlx_xpm_file_to_image(data->mlx,
			"./img/knight1.xpm", &width, &height);
	data->player->player_images[1] = mlx_xpm_file_to_image(data->mlx,
			"./img/knight2.xpm", &width, &height);
	if (!data->player->player_images[0] || !data->player->player_images[1])
		throw_an_error("Failed to initialize player textures", data);
	data->player_img = data->player->player_images[0];
}

static void	init_coin_textures(t_mlx_data *data)
{
	int	width;
	int	height;

	data->coin->coin_images[0] = mlx_xpm_file_to_image(data->mlx,
			"./img/coin1.xpm", &width, &height);
	data->coin->coin_images[1] = mlx_xpm_file_to_image(data->mlx,
			"./img/coin2.xpm", &width, &height);
	data->coin->coin_images[2] = mlx_xpm_file_to_image(data->mlx,
			"./img/coin3.xpm", &width, &height);
	data->coin->coin_images[3] = mlx_xpm_file_to_image(data->mlx,
			"./img/coin4.xpm", &width, &height);
	data->coin->coin_images[4] = mlx_xpm_file_to_image(data->mlx,
			"./img/coin5.xpm", &width, &height);
	data->coin->coin_images[5] = mlx_xpm_file_to_image(data->mlx,
			"./img/coin6.xpm", &width, &height);
	if (!data->coin->coin_images[0] || !data->coin->coin_images[1]
		|| !data->coin->coin_images[1] || !data->coin->coin_images[2]
		|| !data->coin->coin_images[3] || !data->coin->coin_images[4]
		|| !data->coin->coin_images[5])
		throw_an_error("Failed to initialize coin textures", data);
	data->coin_img = data->coin->coin_images[0];
}

void	init_textures(t_mlx_data *data)
{
	int	width;
	int	height;

	init_player_textures(data);
	init_coin_textures(data);
	data->grass_img = mlx_xpm_file_to_image(data->mlx,
			"./img/grass.xpm", &width, &height);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"./img/wall.xpm", &width, &height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			"./img/exit.xpm", &width, &height);
	if (!data->grass_img || !data->wall_img || !data->exit_img)
		throw_an_error("Failed to initialize map textures", data);
}

static void	put_img(t_mlx_data *data, int i, int j)
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
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->grass_img, j * 64, i * 64);
}

void	draw_the_map(t_mlx_data *data)
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
