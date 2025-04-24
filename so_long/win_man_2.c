/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_man_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:57 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:42:58 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "win_man.h"
#include "mlx.h"
#include "utility.h"
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include "map_man.h"

void	win_update_p_col_row(t_all *all, int col_off, int row_off)
{
	t_bm	*bm;

	bm = &all->ber;
	bm->str[bm->p_row * bm->cols + bm->p_col] = '0';
	mlx_put_image_to_window(all->wi.mlx, all->wi.win,
		elem_at(&all->els, '0'), bm->p_col * all->els.comp[0].img_width,
		bm->p_row * all->els.comp[0].img_height);
	bm->p_row += row_off;
	bm->p_col += col_off;
	bm->str[bm->p_row * bm->cols + bm->p_col] = 'P';
}

void	update_exit(t_all all)
{
	int		tmp;
	char	*fname;
	void	*img;

	map_find_exit(&all.ber);
	fname = "img/E_2.xpm";
	img = mlx_xpm_file_to_image(all.wi.mlx, fname, &tmp, &tmp);
	mlx_put_image_to_window(all.wi.mlx, all.wi.win, img,
		all.ber.e_col * all.els.comp[0].img_width,
		all.ber.e_row * all.els.comp[0].img_height);
	mlx_destroy_image(all.wi.mlx, img);
}

void	clear_string(t_all *all)
{
	int		i;
	int		tmp;
	char	*fname;
	void	*img;

	fname = "img/1.xpm";
	i = 0;
	img = mlx_xpm_file_to_image(all->wi.mlx, fname, &tmp, &tmp);
	while (i <= all->els.comp->img_width)
	{
		mlx_put_image_to_window(all->wi.mlx, all->wi.win, img,
			i * all->els.comp[0].img_width,
			(all->ber.rows -1) * all->els.comp[0].img_height);
		i++;
	}
	mlx_destroy_image(all->wi.mlx, img);
}

void	game_over(t_all *all)
{
	void	*img;
	int		tpm;

	mlx_clear_window(all->wi.mlx, all->wi.win);
	img = mlx_xpm_file_to_image(all->wi.mlx, "img/you_died.xpm", &tpm, &tpm);
	mlx_put_image_to_window(all->wi.mlx, all->wi.win, img,
		all->ber.cols, all->ber.rows);
	mlx_destroy_image(all->wi.mlx, img);
	mlx_loop_end(all->wi.mlx);
}

void	victory_achived(t_all *all)
{
	void	*img;
	int		tpm;

	mlx_clear_window(all->wi.mlx, all->wi.win);
	img = mlx_xpm_file_to_image(all->wi.mlx, "img/victory.xpm", &tpm, &tpm);
	mlx_put_image_to_window(all->wi.mlx, all->wi.win,
		img, all->ber.cols, all->ber.rows);
	mlx_destroy_image(all->wi.mlx, img);
	mlx_loop_end(all->wi.mlx);
}
