/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:57:35 by armarake          #+#    #+#             */
/*   Updated: 2025/03/21 18:19:12 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

int	main(void)
{
	t_mlx_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 700, 500, "So long");
	mlx_key_hook(data.mlx_win, handle_key_press, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}