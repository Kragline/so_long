/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:02:16 by armarake          #+#    #+#             */
/*   Updated: 2025/03/28 14:12:00 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

void	clear_textures(t_mlx_data *data)
{
	if (data->grass_img)
	{
		mlx_destroy_image(data->mlx, data->grass_img);
		// free(data->grass_img);
		data->grass_img = NULL;
	}
	if (data->wall_img)
	{
		mlx_destroy_image(data->mlx, data->wall_img);
		// free(data->wall_img);
		data->wall_img = NULL;
	}
	if (data->exit_img)
	{
		mlx_destroy_image(data->mlx, data->exit_img);
		// free(data->exit_img);
		data->exit_img = NULL;
	}
	if (data->coll_img)
	{
		mlx_destroy_image(data->mlx, data->coll_img);
		// free(data->coll_img);
		data->coll_img = NULL;
	}
	if (data->player_img)
	{
		mlx_destroy_image(data->mlx, data->player_img);
		// free(data->player_img);
		data->player_img = NULL;
	}
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
