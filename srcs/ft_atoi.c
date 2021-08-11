/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:44:28 by egums             #+#    #+#             */
/*   Updated: 2020/08/12 11:38:04 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

void		ft_putstr(char *c)
{
	while (*c)
		write(2, c++, 1);
}

int			ft_atoi(char *c, int i)
{
	int		result;
	int		minus;

	result = 0;
	minus = 1;
	while (c[i] >= 9 && c[i] <= 13)
	{
		i++;
		if (c[i] == '-')
			minus = -1;
		if (c[i] == '+' || c[i] == '-')
			i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		result = result * 10 + (c[i] - '0');
		i++;
	}
	g_y = result * minus;
	if (g_y < 0)
		return (-1);
	else
		return (i);
}
