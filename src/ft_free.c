/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:02:16 by armarake          #+#    #+#             */
/*   Updated: 2025/03/29 19:39:49 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

void	clear_textures(t_mlx_data *data)
{
	if (data->grass_img)
		mlx_destroy_image(data->mlx, data->grass_img);
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
	if (data->player->player_images[0])
		mlx_destroy_image(data->mlx, data->player->player_images[0]);
	if (data->player->player_images[1])
		mlx_destroy_image(data->mlx, data->player->player_images[1]);
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
