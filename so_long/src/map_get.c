/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:42:56 by roramos           #+#    #+#             */
/*   Updated: 2022/11/23 19:05:56 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

size_t	get_number_of_columns(char *map_file)
{
	size_t	size;
	int		fd;

	fd = open(map_file, O_RDONLY);
	size = ft_strlen(get_next_line(fd)) - 1;
	close(fd);
	return (size);
}

size_t	get_number_of_rows(char *map_file)
{
	size_t	size;
	int		fd;

	size = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		handle_errors("Couldn't open map's file");
	while (get_next_line(fd))
		size++;
	if (size == 0)
		handle_errors("Map file is empty");
	close(fd);
	return (size);
}

t_map	*get_map(char *map_file)
{
	t_map	*map;
	char	**temp_map;
	int		i;
	int		fd;

	map = malloc(sizeof(map));
	if (!map)
		handle_errors("a");
	map->rows = get_number_of_rows(map_file);
	map->columns = get_number_of_columns(map_file);
	fd = open(map_file, O_RDONLY);
	temp_map = malloc(map->rows * sizeof(char *));
	i = -1;
	while (++i < map->rows)
		temp_map[i] = ft_strtrim(get_next_line(fd), "\n");
	map->map = temp_map;
	return (map);
}
