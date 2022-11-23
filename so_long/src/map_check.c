/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:42:56 by roramos           #+#    #+#             */
/*   Updated: 2022/11/22 19:08:36 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int find_path(t_map *map, int x, int y, int path_finder[map->rows][map->columns])
{
	if (map->map[x][y] == 'E')
		return 1;
	if (x >= 0 && x < map->rows && y >= 0 && y < map->columns && map->map[x][y] != '1')
	{
		if (path_finder[x][y] == 1)
			return 0;
		path_finder[x][y] = 1;
		if (find_path(map, x + 1, y, path_finder) == 1)
			return 1;
		if (find_path(map, x, y + 1, path_finder) == 1)
			return 1;
		if (find_path(map, x - 1, y, path_finder) == 1)
			return 1;
		if (find_path(map, x, y - 1, path_finder) == 1)
			return 1;
		path_finder[x][y] = 0;
		return 0;
	}
	return 0;
}

void	check_path(t_map *map)
{
	int ij[2];
	int path_finder[map->rows][map->columns];
	int coords[2];

	ij[0] = -1;
	while (map->map[++ij[0]])
	{
		ij[1] = -1;
		while (map->map[ij[0]][++ij[1]])
		{
			if (map->map[ij[0]][ij[1]] == 'P')
			{
				coords[0] = ij[0];
				coords[1] = ij[1];
			}
			path_finder[ij[0]][ij[1]] = 0;
		}
	}
	if (find_path(map, coords[0], coords[1], path_finder) == 0)
		handle_errors("!path");
}

void	check_square(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows - 1)
		if (ft_strlen(map->map[i]) != map->columns)
			handle_errors("!square");
}

void	check_walls(t_map *map)
{
	int	i;

	if (ft_strlen(ft_strtrim(map->map[0], "1")) != 0 ||
	ft_strlen(ft_strtrim(map->map[map->rows - 1], "1")) != 0)
		handle_errors("WAll");
	i = 0;
	while (++i < map->rows - 1)
		if ((map->columns - 2) < ft_strlen(ft_strtrim(map->map[i], "1")))
			handle_errors("waLL");
}

void	check_for_icons(t_map *map)
{
	int	i;
	int	j;
	int	has[3];

	has[0] = 0;
	has[1] = 0;
	has[2] = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
				has[0] ++;
			else if (map->map[i][j] == 'P')
				has[1]++;
			else if (map->map[i][j] == 'E')
				has[2]++;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				handle_errors("0");
		}
	}
	if (has[0] < 1)
		handle_errors("C");
	if (has[1] != 1)
		handle_errors("P");
	if (has[2] != 1)
		handle_errors("E");
}

void	map_check(t_map *map)
{
	check_square(map);
	check_walls(map);
	check_for_icons(map);
	check_path(map);
}