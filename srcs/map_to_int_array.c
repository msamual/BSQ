/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_int_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:59:42 by msamual           #+#    #+#             */
/*   Updated: 2020/08/12 23:19:36 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		**map_to_int_array(char *map_char)
{
	int		**map;
	int		x;
	int		y;

	y = 0;
	x = 0;
	map = malloc(sizeof(int *) * g_y + 1);
	map[0] = malloc(sizeof(int) * g_x + 1);
	if (!map || !(map[0]))
		return (NULL);
	while (*map_char)
	{
		if (*map_char == g_empty)
			map[y][x++] = 0;
		if (*map_char == g_obstacle)
			map[y][x++] = -1;
		if (*map_char == '\n' || *map_char == 13)
		{
			y++;
			map[y] = malloc(sizeof(int) * g_x);
			x = 0;
		}
		map_char++;
	}
	return (map);
}

void	print_map(int **map)
{
	int x;
	int y;

	y = -1;
	while (++y < g_y)
	{
		x = -1;
		while (++x < g_x)
		{
			if (map[y][x] == -1)
				write(1, &g_obstacle, 1);
			else if (map[y][x] == -2)
				write(1, &g_full, 1);
			else
				write(1, ".", 1);
		}
		write(1, "\n", 1);
	}
}

int		solve(char *str)
{
	int		max_value;
	int		**map;

	map = map_to_int_array(str);
	max_value = fill_map(&map);
	find_square(&map, max_value, -1, -1);
	print_map(map);
	free(map);
	return (0);
}
