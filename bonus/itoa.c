/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:29:56 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/26 16:10:42 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_len(int n, long *nb)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		*nb *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*ptr;
	int		len;

	nb = n;
	len = ft_len(n, &nb);
	ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	ptr[len--] = '\0';
	while (nb > 0)
	{
		ptr[len--] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	else if (n == 0)
		ptr[0] = '0';
	return (ptr);
}
