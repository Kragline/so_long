/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:49:46 by armarake          #+#    #+#             */
/*   Updated: 2025/03/23 23:34:04 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

int	ends_with_ber(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		throw_an_error("Couldn't open mapfile");
	return (fd);
}

int	dfs(t_map *map, int**visited, int x, int y)
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->cols
		|| map->map[x][y] == '1' || visited[x][y])
		return (0);
	if (map->map[x][y] == 'E')
		return (1);
	visited[x][y] = 1;
	if (dfs(map, visited, x + 1, y) || dfs(map, visited, x - 1, y)
		|| dfs(map, visited, x, y + 1) || dfs(map, visited, x, y - 1))
		return (1);
	return (0);
}

int	surrounded_by_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->cols)
		if (map->map[0][i++] != '1')
			return (0);
	i = 0;
	while (i < map->cols)
		if (map->map[map->rows - 1][i++] != '1')
			return (0);
	i = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1' || map->map[i][map->cols - 1] != '1')
			return (0);
		i++;	
	}
	return (1);
}
