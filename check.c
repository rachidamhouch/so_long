/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:23:36 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/27 00:06:58 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_closed(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			printrror();
		i++;
	}
	i = 1;
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			printrror();
		i++;
	}
}

static int	is_characters(char n)
{
	char	*ptr;
	int		i;

	ptr = "10CPE";
	i = 0;
	while (ptr[i])
	{
		if (n == ptr[i])
			return (1);
		i++;
	}
	return (0);
}

static void	is_characters2(char **map)
{
	t_help	a;

	a.c = 0;
	a.e = 0;
	a.i = 0;
	a.p = 0;
	while (map[a.i])
	{
		a.j = 0;
		while (map[a.i][a.j] && map[a.i][a.j] != '\n')
		{
			if (!is_characters(map[a.i][a.j]))
				printrror();
			if (map[a.i][a.j] == 'E')
				a.e++;
			if (map[a.i][a.j] == 'P')
				a.p++;
			if (map[a.i][a.j++] == 'C')
				a.c++;
		}
		a.i++;
	}
	if (a.c == 0 || a.p == 0 || a.e == 0 || a.p > 1 || a.e > 1)
		printrror();
}

void	rectangular(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < height - 1)
	{
		if (ft_strlen(map[i]) != width)
			printrror();
		i++;
	}
	if (ft_strlen(map[i]) != width - 1)
		printrror();
	is_closed(map, width - 1, height);
	is_characters2(map);
}
