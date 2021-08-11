/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:11:37 by egums             #+#    #+#             */
/*   Updated: 2020/08/12 23:15:20 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_strncpy(char *dest, char *src, char *buf, int n)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (--n > -1)
	{
		dest[i] = *buf;
		buf++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_realloc(char *str, char *buf, int n)
{
	char	*new;
	int		number;

	number = g_bufcount;
	new = malloc(sizeof(char) * (number * 3));
	new = ft_strncpy(new, str, buf, n);
	g_bufcount *= 2;
	free(str);
	free(buf);
	return (new);
}
