/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:58:02 by armarake          #+#    #+#             */
/*   Updated: 2025/04/02 14:55:57 by armarake         ###   ########.fr       */
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
	if (data->counter >= 6000)
	{
		draw_the_map(data);
		render_movecount(data);
		animate_coin(data);
		animate_ghost(data);
		data->counter = 0;
	}
	return (1);
}

void	render_movecount(t_data *data)
{
	char	*count;

	count = ft_itoa(data->player->movements);
	if (!count)
		return ;
	mlx_string_put(data->mlx, data->mlx_win, 10,
		data->map->rows * 64 - 10, 0xFFFFFF, "Movements:");
	mlx_string_put(data->mlx, data->mlx_win, 75,
		data->map->rows * 64 - 10, 0xFFFFFF, count);
	free(count);
}
