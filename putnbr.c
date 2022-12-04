/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:02:10 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/09 20:16:23 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putnbr(int n)
{
	char	t;
	long	nbr;
	int		z;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	z = 1;
	while (nbr / z >= 10)
		z *= 10;
	while (z > 0)
	{
		t = ((nbr / z) % 10) + '0';
		write(1, &t, 1);
		z /= 10;
	}
	write(1, "\n", 1);
}