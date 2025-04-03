/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:51:35 by armarake          #+#    #+#             */
/*   Updated: 2025/04/03 20:49:45 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	defeat_screen(t_data *data)
{
	if (!data)
		return (0);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_string_put(data->mlx, data->mlx_win, ((data->map->cols - 1) * 64) / 2,
		(data->map->rows * 64) / 2, 0xFF0000, "YOU LOST!");
	return (1);
}

static int	victory_screen(t_data *data)
{
	if (!data)
		return (0);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_string_put(data->mlx, data->mlx_win, ((data->map->cols - 1) * 64) / 2,
		(data->map->rows * 64) / 2, 0xFFFFFF, "YOU WON!");
	return (1);
}

int	game_over(t_data *data, int victory)
{
	if (!data)
		return (0);
	if (victory)
		mlx_loop_hook(data->mlx, victory_screen, data);
	else
		mlx_loop_hook(data->mlx, defeat_screen, data);
	return (1);
}
