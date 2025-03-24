/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:26:11 by armarake          #+#    #+#             */
/*   Updated: 2025/03/24 13:35:37 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

static void	move_up(void)
{
}

static void	move_down(void)
{
}

static void	move_left(void)
{
}

static void	move_right(void)
{
}

int	handle_key_press(int keycode, t_mlx_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	else if (keycode == XK_w)
		move_up();
	else if (keycode == XK_s)
		move_down();
	else if (keycode == XK_a)
		move_left();
	else if (keycode == XK_d)
		move_right();
	return (0);
}
