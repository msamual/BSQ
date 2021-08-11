/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:11:57 by msamual           #+#    #+#             */
/*   Updated: 2020/08/11 18:17:17 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_even_square(int ***map, int x, int y, int max_value)
{
	if ((x + 1) > g_x || (y + 1) > g_y)
		return (0);
	if ((*map)[y][x + 1] == max_value && (*map)[y + 1][x] == max_value
			&& (*map)[y + 1][x + 1] == max_value)
		return (1);
	else
		return (0);
}

void	fill_even_square(int ***map, int x, int y, int size)
{
	int i;
	int j;

	j = y - size;
	while (++j < (y + size + 1))
	{
		i = x - size;
		while (++i < (x + size + 1))
			(*map)[j][i] = -2;
	}
}

void	fill_odd_square(int ***map, int x, int y, int size)
{
	int i;
	int j;

	j = y - size;
	while (++j < (y + size))
	{
		i = x - size;
		while (++i < (x + size))
		{
			(*map)[j][i] = -2;
		}
	}
}

void	find_square(int ***map, int max_value, int x, int y)
{
	while (++y < g_y)
	{
		x = -1;
		while (++x < g_x)
			if (((*map)[y][x] == max_value) &&
				check_even_square(map, x, y, max_value))
			{
				fill_even_square(map, x, y, max_value);
				return ;
			}
	}
	y = -1;
	while (++y < g_y)
	{
		x = -1;
		while (++x < g_x)
			if ((*map)[y][x] == max_value)
			{
				fill_odd_square(map, x, y, max_value);
				return ;
			}
	}
}
