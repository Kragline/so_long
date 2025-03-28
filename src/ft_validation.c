/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:55:00 by armarake          #+#    #+#             */
/*   Updated: 2025/03/28 13:50:05 by armarake         ###   ########.fr       */
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

static void	allocate_map(t_mlx_data *data, int line_count)
{
	int		i;
	char	*line;

	data->map->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!(data->map->map))
		throw_an_error("Map allocation failed", NULL);
	line = get_next_line(data->map->map_fd);
	data->map->rows = line_count;
	data->map->cols = ft_strlen(line) - 1;
	i = 0;
	while (line)
	{
		(data->map->map)[i] = ft_strdup(line);
		if (!(data->map->map))
			throw_an_error("Map allocation failed", data);
		i++;
		free(line);
		line = NULL;
		line = get_next_line(data->map->map_fd);
	}
	(data->map->map)[i] = NULL;
}

void	validate_and_allocate(char *filename, t_mlx_data *data)
{
	int	line_count;

	if (!ends_with_ber(filename))
		throw_an_error("Map must have .ber extension", NULL);
	data->map->map_fd = open_map(filename);
	line_count = 0;
	if (!check_map_characters(data->map->map_fd, &line_count))
		throw_an_error("Invalid map", NULL);
	close(data->map->map_fd);
	data->map->map_fd = open_map(filename);
	allocate_map(data, line_count);
	if (!check_exit_path(data))
		throw_an_error("No valid for exit", data);
	if (!check_collectibles_path(data))
		throw_an_error("No valid for collectibles", data);
	if (!surrounded_by_walls(data->map))
		throw_an_error("Map isn't surrounded by walls", data);
	if (data->map->rows == data->map->cols)
		throw_an_error("Map isn't rectangular", data);
}
