/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:55:00 by armarake          #+#    #+#             */
/*   Updated: 2025/03/22 14:55:00 by armarake         ###   ########.fr       */
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

static int	check_map_characters(int map_fd)
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
		free(line);
		line = NULL;
		line = get_next_line(map_fd);
	}
	if (exit_count == 1 && coll_count >= 1 && sp_count == 1)
		return (1);
	return (0);
}

void	validate_map(char *filename, t_map *map)
{
	if (!ends_with_ber(filename))
	{
		ft_putendl_fd("Error\nMap must have .ber extension", 2);
		exit(1);
	}
	map->map_fd = open_map(filename);
	if (!check_map_characters(map->map_fd))
	{
		ft_putendl_fd("Error\nInvalid map", 2);
		exit(1);
	}
}
