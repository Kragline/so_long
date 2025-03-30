/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:58:02 by armarake          #+#    #+#             */
/*   Updated: 2025/03/30 17:25:41 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	animate_coin(t_data *data)
{
	if (data->coin->index == 5)
		data->coin->index = 0;
	else
		data->coin->index++;
	data->coin_img = data->coin->coin_images[data->coin->index];
}

static void	animate_ghost(t_data *data)
{
	if (data->ghost->index == 4)
		data->ghost->direction = -1;
	else if (data->ghost->index == 0)
		data->ghost->direction = 1;
	data->ghost->index += data->ghost->direction;
	data->ghost_img = data->ghost->ghost_images[data->ghost->index];
}

int	render_next_frame(t_data *data)
{
	if (!data)
		return (0);
	data->counter++;
	if (data->counter >= 4000)
	{
		draw_the_map(data);
		render_movecount(data);
		animate_coin(data);
		animate_ghost(data);
		data->counter = 0;
	}
	return (1);
}

int	game_over_screen(t_data *data)
{
	if (!data)
		return (0);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_string_put(data->mlx, data->mlx_win, ((data->map->cols - 1) * 64) / 2,
		(data->map->rows * 64) / 2, 0xFF0000, "GAME OVER!");
	return (1);
}

int	game_over(t_data *data)
{
	if (!data)
		return (0);
	mlx_loop_hook(data->mlx, game_over_screen, data);
	return (1);
}
