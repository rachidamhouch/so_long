/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:12:30 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/26 18:04:47 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_game *a)
{
	static int	mv;

	if (keycode == UP || keycode == UP2)
		up(a, &mv);
	else if (keycode == DOWN || keycode == DOWN2)
		down(a, &mv);
	else if (keycode == LEFT || keycode == LEFT2)
		left(a, &mv);
	else if (keycode == RIGHT || keycode == RIGHT2)
		rifht(a, &mv);
	else if (keycode == ESC)
	{
		mlx_destroy_window(a->mlx, a->win);
		exit(0);
	}
	if (!check_co(*a))
	{
		a->map[a->ey][a->ex] = 'E';
		mlx_clear_window(a->mlx, a->win);
		new_view(a);
	}
	return (0);
}

static int	destroy(t_game *a)
{
	mlx_destroy_window(a->mlx, a->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	so_long;
	int		height;
	int		width;

	if (ac == 2)
	{
		height = 0;
		so_long.map = maptoarr(av[1], &height, &width);
		path_is_valid(so_long, height, width);
		so_long.mlx = mlx_init();
		so_long.p = 1;
		so_long.win = mlx_new_window(so_long.mlx, width * 50, \
			height * 50, "Dragon Ball");
		new_view(&so_long);
		mlx_hook(so_long.win, 2, 0, key_hook, &so_long);
		mlx_hook(so_long.win, 17, 0, destroy, &so_long);
		mlx_loop(so_long.mlx);
	}
}
