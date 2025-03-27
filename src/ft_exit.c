/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:25:19 by armarake          #+#    #+#             */
/*   Updated: 2025/03/27 23:59:17 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

int	close_game(t_mlx_data *data)
{
	if (data->map)
		ft_free_map(data->map->map);
	clear_textures(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	data->mlx_win = NULL;
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
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
