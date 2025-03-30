/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:29:27 by armarake          #+#    #+#             */
/*   Updated: 2025/03/30 17:22:33 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_player_textures(t_data *data)
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

static void	init_ghost_textures(t_data *data)
{
	int	width;
	int	height;

	data->ghost->ghost_images[0] = mlx_xpm_file_to_image(data->mlx,
			"./img/ghost1.xpm", &width, &height);
	data->ghost->ghost_images[1] = mlx_xpm_file_to_image(data->mlx,
			"./img/ghost2.xpm", &width, &height);
	data->ghost->ghost_images[2] = mlx_xpm_file_to_image(data->mlx,
			"./img/ghost3.xpm", &width, &height);
	data->ghost->ghost_images[3] = mlx_xpm_file_to_image(data->mlx,
			"./img/ghost4.xpm", &width, &height);
	data->ghost->ghost_images[4] = mlx_xpm_file_to_image(data->mlx,
			"./img/ghost5.xpm", &width, &height);
	if (!data->ghost->ghost_images[0] || !data->ghost->ghost_images[1]
		|| !data->ghost->ghost_images[2] || !data->ghost->ghost_images[3]
		|| !data->ghost->ghost_images[4])
		throw_an_error("Failed to initialize ghost textures", data);
	data->ghost_img = data->ghost->ghost_images[0];
}

static void	init_coin_textures(t_data *data)
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
		|| !data->coin->coin_images[2] || !data->coin->coin_images[3]
		|| !data->coin->coin_images[4] || !data->coin->coin_images[5])
		throw_an_error("Failed to initialize coin textures", data);
	data->coin_img = data->coin->coin_images[0];
}

void	init_textures(t_data *data)
{
	int	width;
	int	height;

	init_player_textures(data);
	init_coin_textures(data);
	init_ghost_textures(data);
	data->grass_img = mlx_xpm_file_to_image(data->mlx,
			"./img/grass.xpm", &width, &height);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"./img/wall.xpm", &width, &height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			"./img/exit.xpm", &width, &height);
	if (!data->grass_img || !data->wall_img || !data->exit_img)
		throw_an_error("Failed to initialize map textures", data);
}
