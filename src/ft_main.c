/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:57:35 by armarake          #+#    #+#             */
/*   Updated: 2025/03/26 18:10:21 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx_data	data;
	t_map		map;

	if (argc != 2)
		throw_an_error("Usage: ./so_long mapfile", NULL);
	validate_and_allocate(argv[1], &map);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 64 * map.cols,
			64 * map.rows, "So long");
	data.map = &map;
	draw_the_map(&data);
	mlx_key_hook(data.mlx_win, handle_key_press, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
