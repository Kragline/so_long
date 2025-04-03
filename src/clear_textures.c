/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:21:28 by armarake          #+#    #+#             */
/*   Updated: 2025/04/03 21:39:52 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	clear_coin_textures(t_data *data)
{
	int	i;

	if (!data->coin)
		return ;
	i = 0;
	while (i < 6)
	{
		if (data->coin->coin_images[i])
		{
			mlx_destroy_image(data->mlx, data->coin->coin_images[i]);
			data->coin->coin_images[i] = NULL;
		}
		i++;
	}
}

void	clear_ghost_textures(t_data *data)
{
	int	i;

	if (!data->ghost)
		return ;
	i = 0;
	while (i < 5)
	{
		if (data->ghost->ghost_images[i])
		{
			mlx_destroy_image(data->mlx, data->ghost->ghost_images[i]);
			data->coin->coin_images[i] = NULL;
		}
		i++;
	}
}

void	clear_player_textures(t_data *data)
{
	if (!data->player)
		return ;
	if (data->player->player_images[0])
	{
		mlx_destroy_image(data->mlx, data->player->player_images[0]);
		data->player->player_images[0] = NULL;
	}
	if (data->player->player_images[1])
	{
		mlx_destroy_image(data->mlx, data->player->player_images[1]);
		data->player->player_images[1] = NULL;
	}
}

void	clear_textures(t_data *data)
{
	if (!data)
		return ;
	if (data->grass_img)
	{
		mlx_destroy_image(data->mlx, data->grass_img);
		data->grass_img = NULL;
	}
	if (data->wall_img)
	{
		mlx_destroy_image(data->mlx, data->wall_img);
		data->wall_img = NULL;
	}
	if (data->exit_img)
	{
		mlx_destroy_image(data->mlx, data->exit_img);
		data->exit_img = NULL;
	}
	clear_player_textures(data);
	clear_coin_textures(data);
	clear_ghost_textures(data);
}
