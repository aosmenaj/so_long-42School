/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:45 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:42:46 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include <fcntl.h>
#include <unistd.h>

void	display_error(char const *const s)
{
	display_str_nl("Error");
	display_str_nl(s);
}

void	display_str(char const *const s)
{
	write(STDERR_FILENO, s, (size_t)my_strlen(s));
}

void	display_str_nl(char const *const s)
{
	display_str(s);
	write(STDERR_FILENO, "\n", 1);
}

int	file_exists(char const *const fname)
{
	int	check;

	check = open(fname, O_RDONLY);
	close(check);
	if (-1 == check)
		return (0);
	return (1);
}

int	find_char_in_str(char const *const s, char c, int max)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (max > i)
	{
		if (c == s[i])
			return (i);
		++i;
	}
	return (-1);
}
