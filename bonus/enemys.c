/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:51:38 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/26 22:22:36 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	help(char **a, int *i, int *j)
{
	if (a[*i][*j + 1] == '0')
	{
		a[*i][*j] = '0';
		a[*i][*j + 1] = 'M';
		*j += 1;
	}
	else if (a[*i][*j + 1] == 'P')
		lose();
	else
		a[*i][*j] = 'm';
}

static void	help2(char **a, int *i, int *j)
{
	if (a[*i][*j - 1] == '0')
	{
		a[*i][*j] = '0';
		a[*i][*j - 1] = 'm';
	}
	else if (a[*i][*j - 1] == 'P')
		lose();
	else
		a[*i][*j] = 'M';
}

void	move_enemys(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == 'M')
				help(a, &i, &j);
			else if (a[i][j] == 'm')
				help2(a, &i, &j);
			j++;
		}
		i++;
	}
}
