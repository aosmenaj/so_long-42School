/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:48 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:42:49 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include <fcntl.h>
#include <unistd.h>

void	my_atoi(int n, char *fill)
{
	int	i;
	int	copy;

	i = -1;
	copy = n;
	while (copy)
	{
		copy /= 10;
		++i;
	}
	if (i == 2)
	{
		fill[++i] = '\0';
		i--;
	}
	while (i)
	{
		fill[i] = n % 10 + '0';
		n /= 10;
		--i;
	}
	fill[i] = (char)(n + '0');
}

int	my_strcpy(char *dest, char const *const src)
{
	int	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = src[i];
	dest[++i] = '\0';
	return (i);
}

void	my_strcpy_n(char *dest, char const *const src, int howmany)
{
	int	i;

	i = 0;
	while (howmany > i)
	{
		dest[i] = src[i];
		++i;
	}
}

int	my_strlen(char const *const s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	put_str_to_zero(char *s, int length)
{
	int	i;

	i = 0;
	while (length > i)
	{
		s[i] = '\0';
		++i;
	}
}
