/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:10 by armarake          #+#    #+#             */
/*   Updated: 2025/03/30 15:58:51 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_up(t_data *data)
{
	change_position_vertical(data, data->player->y_pos - 1);
	draw_the_map(data);
}

static void	move_down(t_data *data)
{
	change_position_vertical(data, data->player->y_pos + 1);
	draw_the_map(data);
}

static void	move_left(t_data *data)
{
	change_position_horizontal(data, data->player->x_pos - 1);
	data->player_img = data->player->player_images[1];
	draw_the_map(data);
}

static void	move_right(t_data *data)
{
	change_position_horizontal(data, data->player->x_pos + 1);
	data->player_img = data->player->player_images[0];
	draw_the_map(data);
}

int	handle_key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_up(data);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(data);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(data);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(data);
	render_movecount(data);
	return (0);
}
