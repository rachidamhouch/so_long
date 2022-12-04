/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:11:43 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/26 22:14:34 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		px;
	int		py;
	int		p;
	int		ex;
	int		ey;
	int		frames;
	char	*c;
	int		nb;
}t_game;

typedef struct position
{
	int		x;
	int		y;
}t_position;

typedef struct help
{
	int	i;
	int	j;
	int	e;
	int	p;
	int	c;
}t_help;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53

# define UP2    126
# define DOWN2	125
# define LEFT2	123
# define RIGHT2	124

void	putstr(char *s);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);
size_t	my_strlen(const char *s);
char	*my_strjoin(char *s1, char *s2);
char	*my_strchr(const char *s, int c);
void	*my_memcpy(void *dst, const void *src, size_t n);
char	**maptoarr(char *map, int *height, int *width);
void	new_view(t_game *a);
void	move(t_game *a, int width, int height);
void	up(t_game *a);
void	down(t_game *a);
void	left(t_game *a);
void	rifht(t_game *a);
int		check_co(t_game a);
void	putnbr(int n);
void	rectangular(char **map, int width, int height);
void	printrror(void);
void	path_is_valid(t_game a, int height, int width);
char	*ft_itoa(int n);
void	move_enemys(char **a);
void	freetabe(char **tab);
void	win(void);
void	lose(void);

#endif
