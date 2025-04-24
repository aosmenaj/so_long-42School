/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_man_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:14 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:42:15 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_man.h"
#include "utility.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	map_add_char_or_row(t_bm *bm, int *length, int check, char c)
{
	if (-1 == check)
		return (0);
	if (!check && bm->cols && *length == bm->cols)
	{
		++bm->rows;
		*length = 0;
	}
	else
	{
		ber_add_char(bm, c);
		++*length;
	}
	return (1);
}

int	map_check_char(t_bm *bm, int *length, char c)
{
	if (map_is_char_valid(c))
		return (1);
	if ('\n' == c)
	{
		if (!bm->cols)
			bm->cols = *length;
		if (bm->cols == *length)
			return (0);
	}
	if (bm->cols == *length)
		display_error("Unknown character!");
	else
		display_error("Not rectangular map!");
	return (-1);
}

int	map_check_obj_occur(t_bm const *bm, char c)
{
	int	i;
	int	k;
	int	flag;

	i = 1;
	flag = 0;
	while (bm->rows - 1 > i)
	{
		k = 1;
		while (bm->cols - 1 > k)
		{
			if (c == ber_at(bm, k, i))
				++flag;
			++k;
		}
		++i;
	}
	return (flag);
}

int	map_copy(t_bm *dest, t_bm const *const source)
{
	if (!ber_init_or_die(dest, source->cpy))
		return (0);
	dest->cols = source->cols;
	dest->rows = source->rows;
	dest->size = source->size;
	my_strcpy_n(dest->str, source->str, dest->size);
	return (1);
}

int	map_find_start(t_bm *bm)
{
	int	start;

	start = find_char_in_str(bm->str, 'P', bm->size);
	if (!start || !bm->cols)
		return (0);
	bm->p_col = start % bm->cols;
	bm->p_row = start / bm->cols;
	return (start);
}
