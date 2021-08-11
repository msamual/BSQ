/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:06:20 by egums             #+#    #+#             */
/*   Updated: 2020/08/12 23:19:21 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

char		g_empty;
char		g_obstacle;
char		g_full;
int			g_y;
int			g_x;
int			g_bufcount;

int			ft_atoi(char *c, int i);
void		ft_putstr(char *c);
int			ft_putchar(char c);
int			fill_map(int ***map);
int			fill1(int ***map);
void		print_map(int **map);
void		find_square(int ***map, int max_value, int x, int y);
int			solve(char *str);
char		*ft_strncpy(char *dest, char *src, char *buf, int n);
char		*ft_realloc(char *str, char *buf, int n);
int			read_file(char *name, int fd);

#endif
