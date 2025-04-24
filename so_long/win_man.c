/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:43:00 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:43:01 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "win_man.h"
#include "mlx.h"
#include "utility.h"
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include "map_man.h"

int	win_move_checks(t_all *all, int col_off, int row_off)
{
	if ('1' == ber_at(&all->ber, all->ber.p_col + col_off,
			all->ber.p_row + row_off))
		return (0);
	if ('C' == ber_at(&all->ber, all->ber.p_col + col_off,
			all->ber.p_row + row_off))
	{
		--all->ber.coll_num;
		if (all->ber.coll_num == 0)
			update_exit(*all);
	}
	if ('N' == ber_at(&all->ber, all->ber.p_col + col_off,
			all->ber.p_row + row_off))
	{
		game_over(all);
		return (0);
	}
	if ('E' == ber_at(&all->ber, all->ber.p_col + col_off,
			all->ber.p_row + row_off))
	{
		if (all->ber.coll_num)
			return (0);
		victory_achived(all);
		return (0);
	}
	return (1);
}

void	win_move_p(t_all *all, int col_off, int row_off, char dir)
{
	if (!win_move_checks(all, col_off, row_off))
		return ;
	win_move_anim(all, col_off, row_off, dir);
	my_atoi(++all->els.steps_count, &all->els.steps[20]);
	display_str(all->els.steps);
	clear_string(all);
	mlx_string_put(all->wi.mlx, all->wi.win, 0,
		all->ber.rows * all->els.comp[0].img_height,
		0x00FFFFFF, &all->els.steps[1]);
}

void	win_paint(t_all *all)
{
	mlx_clear_window(all->wi.mlx, all->wi.win);
	win_els_paint(all);
	mlx_string_put(all->wi.mlx, all->wi.win, 0,
		all->ber.rows * all->els.comp[0].img_height,
		0x00FFFFFF, &all->els.steps[1]);
}
