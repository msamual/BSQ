/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:46:34 by msamual           #+#    #+#             */
/*   Updated: 2020/08/12 21:43:08 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		define_value(int ***map, int x, int y)
{
	int min;
	int i;
	int j;

	i = x - 2;
	j = y - 2;
	min = 999999;
	while (++j < (y + 2))
	{
		i = x - 2;
		while (++i < (x + 2))
		{
			if (i > -1 && i < g_x && j > -1 && j < g_y)
				if ((*map)[j][i] > 0 && (*map)[j][i] < min)
					min = (*map)[j][i];
		}
	}
	return (min + 1);
}

void	fill_around(int ***map, int x, int y)
{
	int i;

	i = -1;
	x -= 1;
	y -= 1;
	while (++i < 3)
		if ((x + i) > 0 && (x + i) < g_x && y > 0 && y < g_y
				&& (*map)[y][x + i] == 0)
			(*map)[y][x + i] = 1;
	i = 0;
	while (++i < 3)
		if (x > 0 && x < g_x && (y + i) > 0 && (y + i) < g_y
				&& (*map)[y + i][x] == 0)
			(*map)[y + i][x] = 1;
	i = 0;
	y = y + 2;
	while (++i < 3)
		if ((x + i) > 0 && (x + i) < g_x && y > 0
				&& y < g_y && (*map)[y][x + i] == 0)
			(*map)[y][x + i] = 1;
	if ((x + 2) > 0 && (x + 2) < g_x && (y - 1) > 0
			&& (y - 1) < g_y && (*map)[y - 1][x + 2] == 0)
		(*map)[y - 1][x + 2] = 1;
}

int		fill_map(int ***map)
{
	int	x;
	int y;

	y = -1;
	while (++y < g_y)
	{
		x = -1;
		while (++x < g_x)
		{
			if (((y == 0 || y == (g_y - 1) || x == 0
							|| x == (g_x - 1)) && (*map)[y][x] == 0))
				(*map)[y][x] = 1;
			if ((*map)[y][x] == -1)
				fill_around(map, x, y);
		}
	}
	return (fill1(map));
}

int		fill1(int ***map)
{
	int x;
	int y;
	int max_value;

	max_value = 0;
	y = -1;
	while (++y < g_y)
	{
		x = -1;
		while (++x < g_x)
			if ((*map)[y][x] == 0)
				(*map)[y][x] = define_value(map, x, y);
	}
	while (--y > -1)
	{
		x = g_x;
		while (--x > -1)
		{
			if ((*map)[y][x] > 1)
				(*map)[y][x] = define_value(map, x, y);
			if ((*map)[y][x] > max_value)
				max_value = (*map)[y][x];
		}
	}
	return (max_value);
}
