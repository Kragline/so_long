/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:26:11 by armarake          #+#    #+#             */
/*   Updated: 2025/03/28 14:02:37 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

static void	move_up(t_mlx_data *data)
{
	change_position_vertical(data, data->player->y_pos - 1);
	draw_the_map(data);
}

static void	move_down(t_mlx_data *data)
{
	change_position_vertical(data, data->player->y_pos + 1);
	draw_the_map(data);
}

static void	move_left(t_mlx_data *data)
{
	change_position_horizontal(data, data->player->x_pos + 1);
	draw_the_map(data);
}

static void	move_right(t_mlx_data *data)
{
	change_position_horizontal(data, data->player->x_pos - 1);
	draw_the_map(data);
}

int	handle_key_press(int keycode, t_mlx_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	else if (keycode == KEY_W)
		move_up(data);
	else if (keycode == KEY_S)
		move_down(data);
	else if (keycode == KEY_D)
		move_left(data);
	else if (keycode == KEY_A)
		move_right(data);
	render_movecount(data);
	return (0);
}
