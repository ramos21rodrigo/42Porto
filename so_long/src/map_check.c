/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:42:56 by roramos           #+#    #+#             */
/*   Updated: 2022/11/27 17:10:18 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	check_square(t_props *props)
{
	int	i;

	i = -1;
	while (++i < props->map.rows - 1)
		if (ft_strlen(props->map.map[i]) != props->map.columns)
			handle_errors("Error\nInvalid map format!");
}

void	check_walls(t_props *props)
{
	int	i;

	if (ft_strlen(ft_strtrim(props->map.map[0], "1")) != 0
		|| ft_strlen(ft_strtrim(props->map.map[props->map.rows - 1], "1")) != 0)
		handle_errors("Error\nInvalid external walls");
	i = 0;
	while (++i < props->map.rows - 1)
		if (props->map.map[i][0] != WALL
		|| props->map.map[i][props->map.columns - 1] != WALL)
			handle_errors("Error\nInvalid external walls");
}

void	find_path(t_props *props, int x, int y,
	int **path_finder)
{
	if (props->map.map[x][y] == EXIT)
		props->map.reachable_exit = true;
	if (props->map.map[x][y] == COLLECTIBLE && path_finder[x][y] != 1)
		props->map.reachable_cols++;
	if (path_finder[x][y] == 1)
		return ;
	if (!(x >= 0 && x < props->map.rows && y >= 0
			&& y < props->map.columns && props->map.map[x][y] != WALL))
		return ;
	path_finder[x][y] = 1;
	find_path(props, x, y + 1, path_finder);
	find_path(props, x + 1, y, path_finder);
	find_path(props, x, y - 1, path_finder);
	find_path(props, x - 1, y, path_finder);
	return ;
}

void	check_path(t_props *props)
{
	int	i;
	int	j;
	int	**path_finder;

	i = -1;
	path_finder = (int **)malloc(sizeof(int *) * props->map.rows);
	if (!path_finder)
		handle_errors("Error\nError on memory allocation!");
	while (++i < props->map.rows)
	{
		j = -1;
		path_finder[i] = (int *)malloc(sizeof(int) * props->map.columns);
		if (!path_finder[i])
			handle_errors("Error\nError on memory allocation!");
		while (++j < props->map.columns)
			path_finder[i][j] = 0;
	}
	find_position_of(props);
	find_path(props, props->player_x, props->player_y, path_finder);
	if (props->map.reachable_cols != props->map.collectibles)
		handle_errors("Error\nImpossible path to collectibles!");
	if (!props->map.reachable_exit)
		handle_errors("Error\nImpossible path to exit!");
	free (path_finder);
}

void	check_for_icons_and_path(t_props *props)
{
	int	var[4];

	var[0] = 0;
	var[1] = 0;
	var[2] = -1;
	while (++var[2] < props->map.rows)
	{
		var[3] = -1;
		while (++var[3] < props->map.columns)
		{
			if (props->map.map[var[2]][var[3]] == PLAYER)
				var[0]++;
			else if (props->map.map[var[2]][var[3]] == COLLECTIBLE)
				props->map.collectibles ++;
			else if (props->map.map[var[2]][var[3]] == EXIT)
				var[1]++;
			else if (props->map.map[var[2]][var[3]] != FLOOR
				&& props->map.map[var[2]][var[3]] != WALL)
				handle_errors("Error\nInvalid character!");
		}
	}
	check_for_errors_in_icons(props, var[0], var[1]);
}
