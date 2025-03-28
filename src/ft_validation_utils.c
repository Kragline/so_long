/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:49:46 by armarake          #+#    #+#             */
/*   Updated: 2025/03/28 13:52:12 by armarake         ###   ########.fr       */
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
		throw_an_error("Couldn't open mapfile", NULL);
	return (fd);
}

int	**allocate_visited(t_mlx_data *data, int *start_x, int *start_y)
{
	int	i;
	int	**visited;

	i = 0;
	*start_x = -1;
	*start_y = -1;
	visited = (int **)ft_calloc(data->map->rows, sizeof(int *));
	if (!visited)
		throw_an_error("Path check failed", data);
	while (i < data->map->rows - 1)
	{
		visited[i] = (int *)ft_calloc(data->map->cols, sizeof(int));
		if (!visited[i])
		{
			ft_free_visited(visited);
			throw_an_error("Path check failed", data);
		}
		i++;
	}
	return (visited);
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
