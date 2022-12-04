/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:43:14 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/26 19:47:37 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_game a, char *relative_path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(a.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(a.mlx, a.win, img, x, y);
	mlx_destroy_image(a.mlx, img);
}

int	check_co(t_game a)
{
	int	i;
	int	j;

	i = 0;
	while (a.map[i])
	{
		j = 0;
		while (a.map[i][j] != '\0' && a.map[i][j] != '\n')
		{
			if (a.map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	check_helper2(int i, int j, t_position p, t_game *a)
{
	if (a->map[i][j] == 'M')
		put_img(*a, "textures/m.xpm", p.x, p.y);
	else if (a->map[i][j] == 'm')
		put_img(*a, "textures/m2.xpm", p.x, p.y);
	else if (a->map[i][j] == 'E')
	{
		a->ex = j;
		a->ey = i;
		if (check_co(*a))
			a->map[i][j] = '0';
		else
			put_img(*a, "textures/e.xpm", p.x, p.y);
	}
	if (a->map[i][j] == '0')
		put_img(*a, "textures/f.xpm", p.x, p.y);
}

static void	check_helper(int i, int j, t_position p, t_game *a)
{
	if (a->map[i][j] == '1')
		put_img(*a, "textures/w.xpm", p.x, p.y);
	else if (a->map[i][j] == 'P')
	{
		a->px = j;
		a->py = i;
		if (a->p == 1)
			put_img(*a, "textures/p.xpm", p.x, p.y);
		else
			put_img(*a, "textures/p2.xpm", p.x, p.y);
	}
	else if (a->map[i][j] == 'C')
		put_img(*a, a->c, p.x, p.y);
	check_helper2(i, j, p, a);
}

void	new_view(t_game *a)
{
	int			i;
	int			j;
	t_position	p;
	char		*ptr;

	i = 0;
	j = 0;
	p.y = 0;
	while (a->map[i])
	{
		j = 0;
		p.x = 0;
		while (a->map[i][j] != '\0' && a->map[i][j] != '\n')
		{
			check_helper(i, j, p, a);
			j++;
			p.x += 50;
		}
		i++;
		p.y += 50;
	}
	mlx_string_put(a->mlx, a->win, 10, 10, 0x00FFFFFF, "Number Of Movements: ");
	ptr = ft_itoa(a->nb);
	mlx_string_put(a->mlx, a->win, 220, 10, 0x00FFFFFF, ptr);
	free(ptr);
}
