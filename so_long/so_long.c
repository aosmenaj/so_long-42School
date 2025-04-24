/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:36 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:42:37 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map_man.h"
#include "mlx.h"
#include "utility.h"
#include <stdlib.h>
#include <unistd.h>

void	sl_clear_memory(t_all *all)
{
	disp_destroy_comps(&all->wi, &all->els);
	mlx_destroy_window(all->wi.mlx, all->wi.win);
	mlx_destroy_display(all->wi.mlx);
	free(all->wi.mlx);
	ber_free_str(&all->ber);
}

int	sl_get_valid_map(t_all *all, char const *const s)
{
	if (!map_init_or_die(&all->ber, s))
		return (0);
	return (disp_init_or_die(&all->wi, &all->els));
}

int	sl_solong(char const *const fname)
{
	t_all	all;

	if (!sl_get_valid_map(&all, fname))
		return (0);
	win_init(&all);
	win_paint(&all);
	mlx_hook(all.wi.win, 17, 0, disp_ondestroy, all.wi.mlx);
	mlx_key_hook(all.wi.win, win_key_init, &all);
	map_find_start(&all.ber);
	mlx_loop(all.wi.mlx);
	usleep(400000);
	sl_clear_memory(&all);
	display_str("\n");
	return (1);
}
