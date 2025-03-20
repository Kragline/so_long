/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:57:35 by armarake          #+#    #+#             */
/*   Updated: 2025/03/19 19:57:35 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

static int	handle_key_press(int keycode, t_mlx_data *data)
{
	if (keycode == XK_Escape)
	{
		ft_printf("Key %d (ESC) was pressed\n", keycode);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	ft_printf("Key %d was pressed\n", keycode);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 700, 500, "So long");
	mlx_key_hook(data.mlx_win, handle_key_press, &data);
	mlx_loop(data.mlx);
	return (0);
}