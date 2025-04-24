/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_man_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:17 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/30 19:16:01 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_man.h"
#include "utility.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	map_find_exit(t_bm *bm)
{
	int	exit;

	exit = find_char_in_str(bm->str, 'E', bm->size);
	if (!exit || !bm->cols)
		return (0);
	bm->e_col = exit % bm->cols;
	bm->e_row = exit / bm->cols;
	return (exit);
}

void	map_flood_fill(t_bm *bm)
{
	if (!map_is_inside_map(bm))
		return ;
	if (skip_char(bm))
		return ;
	if ('C' == ber_at(bm, bm->p_col, bm->p_row))
		++bm->coll_num;
	if ('E' == ber_at(bm, bm->p_col, bm->p_row))
	{
		bm->str[bm->p_row * bm->cols + bm->p_col] = ' ';
		++bm->exit_num;
		return ;
	}
	bm->str[bm->p_row * bm->cols + bm->p_col] = ' ';
	--bm->p_row;
	map_flood_fill(bm);
	++bm->p_row;
	++bm->p_col;
	map_flood_fill(bm);
	--bm->p_col;
	++bm->p_row;
	map_flood_fill(bm);
	--bm->p_row;
	--bm->p_col;
	map_flood_fill(bm);
	++bm->p_col;
}

int	map_init_ber_data(t_bm *bm, const char *const fname)
{
	int	fd;

	if (!ber_init_or_die(bm, 0))
		return (0);
	fd = map_open(fname);
	if (-1 == fd)
	{
		ber_free_str(bm);
		return (0);
	}
	if (!map_read(bm, fd))
	{
		ber_free_str(bm);
		return (0);
	}
	close(fd);
	return (1);
}

int	map_init_or_die(t_bm *bm, char const *const fname)
{
	if (!map_init_ber_data(bm, fname))
		return (0);
	if (!map_is_map_valid(bm))
	{
		ber_free_str(bm);
		return (0);
	}
	return (1);
}

int	map_is_char_valid(char c)
{
	if ('0' == c || '1' == c || 'C' == c || 'E' == c || 'P' == c || 'N' == c)
		return (1);
	return (0);
}
