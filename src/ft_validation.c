/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:55:00 by armarake          #+#    #+#             */
/*   Updated: 2025/03/26 17:32:26 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_so_long.h"

static int	check_the_line(char *s, int *e_count, int *c_count, int *sp_count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'E')
			(*e_count)++;
		else if (s[i] == 'C')
			(*c_count)++;
		else if (s[i] == 'P')
			(*sp_count)++;
		else if (s[i] != '0' && s[i] != '1' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	check_map_characters(int map_fd, int *line_count)
{
	char	*line;
	int		exit_count;
	int		coll_count;
	int		sp_count;

	exit_count = 0;
	coll_count = 0;
	sp_count = 0;
	line = get_next_line(map_fd);
	while (line)
	{
		if (!check_the_line(line, &exit_count, &coll_count, &sp_count))
		{
			free(line);
			line = NULL;
			return (0);
		}
		(*line_count)++;
		free(line);
		line = NULL;
		line = get_next_line(map_fd);
	}
	if (exit_count == 1 && coll_count >= 1 && sp_count == 1)
		return (1);
	return (0);
}

static void	allocate_map(t_map *map, int line_count)
{
	int		i;
	char	*line;

	map->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!(map->map))
		throw_an_error("Map allocation failed", NULL);
	line = get_next_line(map->map_fd);
	map->rows = line_count;
	map->cols = ft_strlen(line) - 1;
	i = 0;
	while (line)
	{
		(map->map)[i] = ft_strdup(line);
		if (!(map->map))
			throw_an_error("Map allocation failed", map);
		i++;
		free(line);
		line = NULL;
		line = get_next_line(map->map_fd);
	}
	(map->map)[i] = NULL;
}

void	validate_and_allocate(char *filename, t_map *map)
{
	int	line_count;

	if (!ends_with_ber(filename))
		throw_an_error("Map must have .ber extension", NULL);
	map->map_fd = open_map(filename);
	line_count = 0;
	if (!check_map_characters(map->map_fd, &line_count))
		throw_an_error("Invalid map", NULL);
	close(map->map_fd);
	map->map_fd = open_map(filename);
	allocate_map(map, line_count);
	if (!check_exit_path(map))
		throw_an_error("No valid for exit", map);
	if (!check_collectibles_path(map))
		throw_an_error("No valid for collectibles", map);
	if (!surrounded_by_walls(map))
		throw_an_error("Map isn't surrounded by walls", map);
	if (map->rows == map->cols)
		throw_an_error("Map isn't rectangular", map);
}
