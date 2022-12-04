/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:32:50 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/26 18:13:55 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**cpymap(char **map, int height, int width)
{
	char	**ptr;
	int		i;
	int		j;

	ptr = malloc((height + 1) * sizeof(char *));
	i = 0;
	while (i < height)
	{
		ptr[i] = malloc(width + 1);
		i++;
	}
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ptr[i][j] = map[i][j];
			j++;
		}
		ptr[i][j] = '\0';
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

static void	helpx(char **map, int i, int j, int	*n)
{
	int	x;

	x = 0;
	*n = 0;
	while (map[i][j + x] != '1')
	{
		if (map[i][j + x] != 'P')
			*n += 1;
		map[i][j + x] = 'P';
		x++;
	}
	x = 0;
	while (map[i][j + x] != '1')
	{
		if (map[i][j + x] != 'P')
			*n += 1;
		map[i][j + x] = 'P';
		x--;
	}
}

static void	helpy(char **map, int i, int j, int	*n)
{
	int	x;

	x = 0;
	*n = 0;
	while (map[i + x][j] != '1')
	{
		if (map[i + x][j] != 'P')
			*n += 1;
		map[i + x][j] = 'P';
		x++;
	}
	x = 0;
	while (map[i + x][j] != '1')
	{
		if (map[i + x][j] != 'P')
			*n += 1;
		map[i + x][j] = 'P';
		x--;
	}
}

static void	find_paths(char **map)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				helpx(map, i, j, &n);
				if (n)
					find_paths(map);
				helpy(map, i, j, &n);
				if (n)
					find_paths(map);
			}
			j++;
		}
		i++;
	}
}

void	path_is_valid(t_game a, int height, int width)
{
	char	**cpy;
	int		i;
	int		j;

	i = 0;
	cpy = cpymap(a.map, height, width);
	find_paths(cpy);
	i = 0;
	while (cpy[i])
	{
		j = 0;
		while (cpy[i][j])
		{
			if (cpy[i][j] == 'E' || cpy[i][j] == 'C')
				printrror();
			j++;
		}
		i++;
	}
	freetabe(cpy);
}
