/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:17:23 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/26 22:27:09 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_exist(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
	{
		fd = open(map, O_RDONLY);
		if (fd == -1)
		{
			putstr("Error\nMap: No such file");
			close(fd);
			exit(1);
		}
	}
	else
	{
		putstr("Error\nMap: No such file");
		close(fd);
		exit(1);
	}
}

static void	extension(char *map)
{
	int	i;

	i = ft_strlen(map) - 1;
	if (map[i--] != 'r')
	{
		putstr("Map is not valid (.ber)");
		exit(1);
	}
	if (map[i--] != 'e')
	{
		putstr("Map is not valid (.ber)");
		exit(1);
	}
	if (map[i--] != 'b')
	{
		putstr("Map is not valid (.ber)");
		exit(1);
	}
	if (map[i--] != '.')
	{
		putstr("Map is not valid (.ber)");
		exit(1);
	}
}

static void	check(char *map)
{
	is_exist(map);
	extension(map);
}

char	**maptoarr(char *map, int *height, int *width)
{
	int		fd;
	char	*ptr;
	char	**tab;
	int		i;

	check(map);
	fd = open(map, O_RDWR);
	i = 0;
	ptr = get_next_line(fd);
	*width = ft_strlen(ptr);
	while (ptr)
	{
		*height = *height + 1;
		free(ptr);
		ptr = get_next_line(fd);
	}
	close(fd);
	tab = malloc((*height + 1) * sizeof(char *));
	fd = open(map, O_RDWR);
	while (i < *height)
		tab[i++] = get_next_line(fd);
	tab[*height] = 0;
	rectangular(tab, *width, *height);
	*width -= 1;
	return (tab);
}
