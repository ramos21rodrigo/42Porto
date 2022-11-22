/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:45:48 by roramos           #+#    #+#             */
/*   Updated: 2022/11/22 18:59:09 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

typedef struct map {
	char	**map;
	int		rows;
	int		column;
}				t_map;

t_map	*get_map(char *map_file);
void    map_check(t_map *map);
void    handle_errors(char *message);

#endif