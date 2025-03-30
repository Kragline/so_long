/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:02:39 by armarake          #+#    #+#             */
/*   Updated: 2025/03/30 15:58:51 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	exit_dfs(t_map *map, int**visited, int x, int y)
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->cols
		|| map->map[x][y] == '1' || map->map[x][y] == 'G' || visited[x][y])
		return (0);
	if (map->map[x][y] == 'E')
		return (1);
	visited[x][y] = 1;
	if (exit_dfs(map, visited, x + 1, y) || exit_dfs(map, visited, x - 1, y)
		|| exit_dfs(map, visited, x, y + 1) || exit_dfs(map, visited, x, y - 1))
		return (1);
	return (0);
}

int	check_exit_path(t_data *data)
{
	int	**visited;
	int	start_x;
	int	start_y;

	visited = allocate_visited(data, &start_x, &start_y);
	find_starting_position(data->map, &start_x, &start_y);
	if (exit_dfs(data->map, visited, start_x, start_y))
	{
		ft_free_visited(visited);
		return (1);
	}
	ft_free_visited(visited);
	return (0);
}

static void	find_collectibles_count(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->collectibles_count = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'C')
				map->collectibles_count++;
			j++;
		}
		i++;
	}
}

static int	collectable_dfs(t_map *map, int **visited, int x, int y)
{
	int	count;

	count = 0;
	if (x < 0 || x >= map->rows || y < 0 || y >= map->cols
		|| map->map[x][y] == '1' || map->map[x][y] == 'G' || visited[x][y])
		return (0);
	visited[x][y] = 1;
	if (map->map[x][y] == 'C')
		count++;
	count += collectable_dfs(map, visited, x + 1, y);
	count += collectable_dfs(map, visited, x - 1, y);
	count += collectable_dfs(map, visited, x, y + 1);
	count += collectable_dfs(map, visited, x, y - 1);
	return (count);
}

int	check_collectibles_path(t_data *data)
{
	int	**visited;
	int	start_x;
	int	start_y;
	int	collected;

	visited = allocate_visited(data, &start_x, &start_y);
	find_starting_position(data->map, &start_x, &start_y);
	find_collectibles_count(data->map);
	collected = collectable_dfs(data->map, visited, start_x, start_y);
	ft_free_visited(visited);
	return (collected == data->map->collectibles_count);
}
