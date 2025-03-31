/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:18 by armarake          #+#    #+#             */
/*   Updated: 2025/03/31 14:12:47 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	clear_coin_textures(t_data *data)
{
	if (data->coin->coin_images[0])
		mlx_destroy_image(data->mlx, data->coin->coin_images[0]);
	if (data->coin->coin_images[1])
		mlx_destroy_image(data->mlx, data->coin->coin_images[1]);
	if (data->coin->coin_images[2])
		mlx_destroy_image(data->mlx, data->coin->coin_images[2]);
	if (data->coin->coin_images[3])
		mlx_destroy_image(data->mlx, data->coin->coin_images[3]);
	if (data->coin->coin_images[4])
		mlx_destroy_image(data->mlx, data->coin->coin_images[4]);
	if (data->coin->coin_images[5])
		mlx_destroy_image(data->mlx, data->coin->coin_images[5]);
}

static void	clear_ghost_textures(t_data *data)
{
	if (data->ghost->ghost_images[0])
		mlx_destroy_image(data->mlx, data->ghost->ghost_images[0]);
	if (data->ghost->ghost_images[1])
		mlx_destroy_image(data->mlx, data->ghost->ghost_images[1]);
	if (data->ghost->ghost_images[2])
		mlx_destroy_image(data->mlx, data->ghost->ghost_images[2]);
	if (data->ghost->ghost_images[3])
		mlx_destroy_image(data->mlx, data->ghost->ghost_images[3]);
	if (data->ghost->ghost_images[4])
		mlx_destroy_image(data->mlx, data->ghost->ghost_images[4]);
}

void	clear_textures(t_data *data)
{
	if (!data->grass_img)
		return ;
	if (!data->wall_img)
		return ;
	if (!data->exit_img)
		return ;
	if (!data->player->player_images[0])
		return ;
	if (!data->player->player_images[1])
		return ;
	mlx_destroy_image(data->mlx, data->grass_img);
	mlx_destroy_image(data->mlx, data->wall_img);
	mlx_destroy_image(data->mlx, data->exit_img);
	mlx_destroy_image(data->mlx, data->player->player_images[0]);
	mlx_destroy_image(data->mlx, data->player->player_images[1]);
	clear_coin_textures(data);
	clear_ghost_textures(data);
}

void	ft_free_map(char **tab)
{
	int	i;

	if (!*tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_visited(int **tab)
{
	int	i;

	if (!*tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
