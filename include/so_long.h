/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:57:33 by armarake          #+#    #+#             */
/*   Updated: 2025/04/03 21:23:25 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

# define KEY_ESC 65307

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_map
{
	int		map_fd;
	char	**map;
	int		rows;
	int		cols;
	int		coin_count;
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

typedef struct s_ghost
{
	int		index;
	int		direction;
	void	*ghost_images[5];
}	t_ghost;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*grass_img;
	void		*wall_img;
	void		*coin_img;
	void		*exit_img;
	void		*player_img;
	void		*ghost_img;
	int			counter;
	t_map		*map;
	t_player	*player;
	t_coin		*coin;
	t_ghost		*ghost;
}	t_data;

//				Validation
int		open_map(char *filename);
int		ends_with_ber(char *filename);
void	validate_and_allocate(char *filename, t_data *data);
int		surrounded_by_walls(t_map *map);
int		is_rectangular(t_map *map);
void	find_starting_position(t_map *map, int *start_x, int *start_y);
int		**allocate_visited(t_data *map, int *start_x, int *start_y);
int		check_exit_path(t_data *data);
int		check_coins_path(t_data *map);

//				Initialization
t_data	init_data(t_map *map, t_player *player, t_coin *coin, t_ghost *ghost);
void	init_textures(t_data *data);
void	draw_the_map(t_data *data);

//				Movements
int		handle_key_press(int keycode, t_data *data);
void	change_position_vertical(t_data *data, int new_y);
void	change_position_horizontal(t_data *data, int new_x);
void	render_movecount(t_data *data);

//				Rendering
int		render_next_frame(t_data *data);
int		game_over(t_data *data, int victory);

//				Free and exit
void	ft_free_map(char **tab);
void	ft_free_visited(int **tab);
void	clear_textures(t_data *data);
void	clear_coin_textures(t_data *data);
void	clear_ghost_textures(t_data *data);
void	clear_player_textures(t_data *data);
int		close_game(t_data *data);
void	throw_an_error(char *message, t_data *data);

#endif