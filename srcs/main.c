/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:05:55 by egums             #+#    #+#             */
/*   Updated: 2020/08/12 23:02:55 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "header.h"
#include <unistd.h>

int			ft_check_obstacles(char *map, int i)
{
	while (map[i] != '\n' && map[i] != 13)
	{
		if (map[i] != g_empty && map[i] != g_obstacle && map[i] != g_full)
			return (-1);
		g_x++;
		i++;
	}
	i++;
	return (i);
}

int			ft_check_xy(char *map, int i, int x)
{
	int		y;

	y = 1;
	while (map[i] != '\0')
	{
		if (map[i] != g_empty && map[i] != g_obstacle && map[i] != g_full &&
			map[i] != '\n')
			return (-1);
		if (map[i] == '\n' || map[i] == 13)
		{
			y++;
			if (x != g_x)
				return (-1);
			x = 0;
			if (y < g_y)
				i++;
		}
		x++;
		i++;
	}
	if (y != g_y)
		return (-1);
	else
		return (1);
}

int			ft_check(char *map)
{
	int		i;
	int		x;
	int		len;

	i = 0;
	x = 0;
	if (0 > (i = ft_atoi(map, i)))
		return (-1);
	g_empty = map[i++];
	g_obstacle = map[i++];
	g_full = map[i++];
	if (map[i++] != '\n')
		return (-1);
	len = i;
	if (0 > (i = ft_check_obstacles(map, i)))
		return (-1);
	if (ft_check_xy(map, i, x) < 0)
		return (-1);
	else
		solve(map + len);
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;

	i = 0;
	g_bufcount = 128;
	if (argc < 2)
	{
		if (!read_file(argv[i], 0))
			ft_putstr("map error\n");
	}
	else
	{
		i = 0;
		while (argv[++i] != NULL)
		{
			g_x = 0;
			g_bufcount = 128;
			if (!read_file(argv[i], -1))
				ft_putstr("map error\n");
			if (argv[i + 1] != NULL)
				ft_putchar('\n');
		}
	}
	return (0);
}

int			read_file(char *name, int fd)
{
	char	*buf;
	int		ret;
	char	*map;

	ret = 0;
	if (fd == -1)
		fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * (g_bufcount) + 1);
	map = malloc(sizeof(char));
	*map = '\0';
	while ((ret = read(fd, buf, g_bufcount)))
	{
		if (ret == -1)
			return (0);
		map = ft_realloc(map, buf, ret);
		buf = malloc(sizeof(char) * (g_bufcount) + 1);
	}
	free(buf);
	close(fd);
	if (ft_check(map) < 0)
		ft_putstr("map error\n");
	free(map);
	return (1);
}
