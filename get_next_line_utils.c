/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:40:50 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/20 21:43:54 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*my_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (0);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (dst);
}

size_t	my_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

char	*my_strjoin(char *s1, char *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*ptr;

	if (!s2)
		return (0);
	ls2 = my_strlen(s2);
	if (!s1)
		ls1 = 0;
	else
		ls1 = my_strlen(s1);
	ptr = malloc(ls1 + ls2 + 1);
	if (!ptr)
		return (0);
	if (!s1)
		my_memcpy(ptr, s2, ls2);
	else
	{
		my_memcpy(ptr, s1, ls1);
		my_memcpy(ptr + ls1, s2, ls2);
	}
	ptr[ls1 + ls2] = '\0';
	free(s1);
	return (ptr);
}

char	*my_strchr(const char *s, int c)
{
	char	*n;

	n = (char *)s;
	if (!s)
		return (0);
	while (*n)
	{
		if (*n == (char) c)
			return (n);
		n++;
	}
	if (*n == (char) c)
		return (n);
	return (0);
}
