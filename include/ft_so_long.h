/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:57:33 by armarake          #+#    #+#             */
/*   Updated: 2025/03/22 19:06:36 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_data;

typedef struct s_map
{
	int		map_fd;
	char	**map;
}	t_map;

int		handle_key_press(int keycode, t_mlx_data *data);
int		close_window(t_mlx_data *data);
void	validate_map(char *filename, t_map *map);
int		ends_with_ber(char *filename);
int		open_map(char *filename);

#endif