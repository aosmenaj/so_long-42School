/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:23 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/05/07 19:20:40 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_man.h"
#include "utility.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	map_is_map_valid(t_bm *bm)
{
	if (!map_size_is_good(bm))
		return (0);
	bm->exit_num = map_check_obj_occur(bm, 'E');
	if (1 > bm->exit_num)
	{
		display_error("Missing exit!");
		return (0);
	}
	if (1 != map_check_obj_occur(bm, 'P') || bm->exit_num > 1)
	{
		if (1 > map_check_obj_occur(bm, 'P'))
			display_error("Missing player!");
		else if (1 < map_check_obj_occur(bm, 'P') || bm->exit_num > 1)
			display_error("Duplicate charcter!");
		return (0);
	}
	bm->coll_num = map_check_obj_occur(bm, 'C');
	if (!bm->coll_num)
	{
		display_error("Missing collectable!");
		return (0);
	}
	if (!map_wall_are_solid(bm))
		return (0);
	return (map_is_map_passable(bm));
}

int	map_open(char const *const fname)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (-1 == fd)
		perror("open failed()");
	return (fd);
}

int	map_read(t_bm *bm, int fd)
{
	int		length;
	int		check;
	char	c;
	ssize_t	tile;

	tile = read(fd, &c, 1);
	length = 0;
	while (tile && -1 != tile)
	{
		check = map_check_char(bm, &length, c);
		if (!map_add_char_or_row(bm, &length, check, c))
			return (0);
		tile = read(fd, &c, 1);
	}
	++bm->rows;
	return (1);
}

int	map_size_is_good(t_bm const *bm)
{
	if (bm->cols * bm->rows != bm->size)
		return (0);
	return (1);
}

int	map_wall_are_solid(t_bm const *bm)
{
	int	i;
	int	k;

	i = 0;
	while (bm->rows > i)
	{
		k = 0;
		while (bm->cols > k)
		{
			if ('1' != ber_at(bm, k, i))
			{
				display_error("Not solid walls!");
				return (0);
			}
			if (!i || bm->rows - 1 == i)
				++k;
			else
				k += bm->cols - 1;
		}
		++i;
	}
	return (1);
}
