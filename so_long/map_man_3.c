/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_man_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:20 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/30 19:19:16 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_man.h"
#include "utility.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	map_is_inside_map(t_bm *bm)
{
	return (0 < bm->p_col && bm->p_col < bm->cols - 1
		&& 0 < bm->p_row && bm->p_row < bm->rows - 1);
}

int	map_is_map_passable(t_bm const *orig)
{
	t_bm	copy;

	if (!map_copy(&copy, orig))
		return (0);
	if (!map_find_start(&copy))
		return (0);
	copy.str[copy.p_row * copy.cols + copy.p_col] = '0';
	map_flood_fill(&copy);
	free(copy.str);
	if (orig->coll_num != copy.coll_num || orig->exit_num != copy.exit_num)
		display_error("Not playable map!");
	return (orig->coll_num == copy.coll_num && orig->exit_num == copy.exit_num);
}

int	skip_char(t_bm *bm)
{
	if ('1' == ber_at(bm, bm->p_col, bm->p_row)
		|| ' ' == ber_at(bm, bm->p_col, bm->p_row)
		|| 'N' == ber_at(bm, bm->p_col, bm->p_row))
		return (1);
	else
		return (0);
}
