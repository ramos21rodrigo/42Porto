/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:42:56 by roramos           #+#    #+#             */
/*   Updated: 2022/11/29 16:07:08 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

size_t	get_number_of_columns(char *map_file)
{
	size_t	size;
	int		fd;

	fd = open(map_file, O_RDONLY);
	size = ft_strlen(get_next_line(fd)) - 1;
	close(fd);
	return (size);
}

size_t	get_number_of_rows(char *map_file, t_props *props)
{
	size_t	size;
	int		fd;

	size = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		handle_errors("Error\nCouldn't open map's file",props);
	while (get_next_line(fd))
		size++;
	if (size == 0)
		handle_errors("Error\nMap file is empty",props);
	close(fd);
	return (size);
}

void	get_map(t_props *props, char *map_file)
{
	char	**temp_map;
	int		i;
	int		fd;

	props->map.rows = get_number_of_rows(map_file, props);
	props->map.columns = get_number_of_columns(map_file);
	fd = open(map_file, O_RDONLY);
	temp_map = malloc(props->map.rows * sizeof(char *));
	i = -1;
	while (++i < props->map.rows)
		temp_map[i] = ft_strtrim(get_next_line(fd), "\n");
	props->map.map = temp_map;
}

void	find_position_of(t_props *props)
{
	int	i;
	int	j;

	i = -1;
	while (++i < props->map.rows)
	{
		j = -1;
		while (++j < props->map.columns)
		{
			if (props->map.map[i][j] == PLAYER)
			{
				props->player_x = i;
				props->player_y = j;
			}
			else if (props->map.map[i][j] == EXIT)
			{
				props->map.door_x = i;
				props->map.door_y = j;
			}
		}
	}
}
