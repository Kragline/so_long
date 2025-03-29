/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:26:11 by armarake          #+#    #+#             */
/*   Updated: 2025/03/29 23:33:45 by armarake         ###   ########.fr       */
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
	change_position_horizontal(data, data->player->x_pos - 1);
	data->player_img = data->player->player_images[1];
	draw_the_map(data);
}

static void	move_right(t_mlx_data *data)
{
	change_position_horizontal(data, data->player->x_pos + 1);
	data->player_img = data->player->player_images[0];
	draw_the_map(data);
}

int	handle_key_press(int keycode, t_mlx_data *data)
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
