/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:25:19 by armarake          #+#    #+#             */
/*   Updated: 2025/03/26 20:35:04 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

static void	clear_textures(t_mlx_data *data)
{
	if (data->grass_img)
		mlx_destroy_image(data->mlx, data->grass_img);
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
	if (data->coll_img)
		mlx_destroy_image(data->mlx, data->coll_img);
}

int	close_window(t_mlx_data *data)
{
	if (data->map)
		ft_free_map(data->map->map);
	clear_textures(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	throw_an_error(char *message, t_map *map)
{
	if (map)
		ft_free_map(map->map);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}
