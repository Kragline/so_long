/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:57:33 by armarake          #+#    #+#             */
/*   Updated: 2025/03/29 19:45:48 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_map
{
	int		map_fd;
	char	**map;
	int		rows;
	int		cols;
	int		collectibles_count;
}	t_map;

typedef struct s_player
{
	int		x_pos;
	int		y_pos;
	int		collected;
	int		movements;
	void	*player_images[2];
}	t_player;

typedef struct s_coin
{
	int			index;
	void		*coin_images[6];
}	t_coin;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*mlx_win;
	void		*grass_img;
	void		*wall_img;
	void		*coin_img;
	void		*exit_img;
	void		*player_img;
	int			counter;
	t_map		*map;
	t_player	*player;
	t_coin		*coin;
}	t_mlx_data;

int		handle_key_press(int keycode, t_mlx_data *data);
int		close_game(t_mlx_data *data);
void	validate_and_allocate(char *filename, t_mlx_data *data);
int		ends_with_ber(char *filename);
int		open_map(char *filename);
void	throw_an_error(char *message, t_mlx_data *data);
void	find_starting_position(t_map *map, int *start_x, int *start_y);
int		surrounded_by_walls(t_map *map);
void	ft_free_map(char **tab);
void	ft_free_visited(int **tab);
int		**allocate_visited(t_mlx_data *map, int *start_x, int *start_y);
int		check_exit_path(t_mlx_data *data);
int		check_collectibles_path(t_mlx_data *map);
void	draw_the_map(t_mlx_data *data);
void	clear_textures(t_mlx_data *data);
void	change_position_vertical(t_mlx_data *data, int new_y);
void	change_position_horizontal(t_mlx_data *data, int new_x);
void	init_data(t_mlx_data *data, t_player *player, t_map *map, t_coin *coin);
void	render_movecount(t_mlx_data *data);
void	init_textures(t_mlx_data *data);

#endif