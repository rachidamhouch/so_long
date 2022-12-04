/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:31:27 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/26 22:19:58 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *a)
{
	if (a->map[a->py - 1][a->px] == '0')
	{
		a->map[a->py - 1][a->px] = 'P';
		a->map[a->py][a->px] = '0';
		a->nb++;
	}
	if (a->map[a->py - 1][a->px] == 'C')
	{
		a->map[a->py - 1][a->px] = 'P';
		a->map[a->py][a->px] = '0';
		a->nb++;
	}
	if (a->map[a->py - 1][a->px] == 'E')
		win();
	if (a->map[a->py - 1][a->px] == 'M' || a->map[a->py - 1][a->px] == 'm')
		lose();
	mlx_clear_window(a->mlx, a->win);
	new_view(a);
}

void	down(t_game *a)
{
	if (a->map[a->py + 1][a->px] == '0')
	{
		a->map[a->py + 1][a->px] = 'P';
		a->map[a->py][a->px] = '0';
		a->nb++;
	}
	if (a->map[a->py + 1][a->px] == 'C')
	{
		a->map[a->py + 1][a->px] = 'P';
		a->map[a->py][a->px] = '0';
		a->nb++;
	}
	if (a->map[a->py + 1][a->px] == 'E')
		win();
	if (a->map[a->py + 1][a->px] == 'm' || a->map[a->py + 1][a->px] == 'M')
		lose();
	mlx_clear_window(a->mlx, a->win);
	new_view(a);
}

void	left(t_game *a)
{
	if (a->map[a->py][a->px - 1] == '0')
	{
		a->map[a->py][a->px - 1] = 'P';
		a->map[a->py][a->px] = '0';
		a->nb++;
	}
	if (a->map[a->py][a->px - 1] == 'C')
	{
		a->map[a->py][a->px - 1] = 'P';
		a->map[a->py][a->px] = '0';
		a->nb++;
	}
	if (a->map[a->py][a->px - 1] == 'E')
		win();
	if (a->map[a->py][a->px - 1] == 'm' || a->map[a->py][a->px - 1] == 'M')
		lose();
	a->p = 0;
	mlx_clear_window(a->mlx, a->win);
	new_view(a);
}

void	rifht(t_game *a)
{
	if (a->map[a->py][a->px + 1] == '0')
	{
		a->map[a->py][a->px + 1] = 'P';
		a->map[a->py][a->px] = '0';
		a->nb++;
	}
	if (a->map[a->py][a->px + 1] == 'C')
	{
		a->map[a->py][a->px + 1] = 'P';
		a->map[a->py][a->px] = '0';
		a->nb++;
	}
	if (a->map[a->py][a->px + 1] == 'E')
		win();
	if (a->map[a->py][a->px + 1] == 'm' || a->map[a->py][a->px + 1] == 'M')
		lose();
	a->p = 1;
	mlx_clear_window(a->mlx, a->win);
	new_view(a);
}
