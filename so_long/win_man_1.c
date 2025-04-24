/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_man_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:54 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:42:55 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "win_man.h"
#include "mlx.h"
#include "utility.h"
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include "map_man.h"

void	win_els_paint(t_all *all)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (all->ber.rows > row)
	{
		col = 0;
		while (all->ber.cols > col)
		{
			c = ber_at(&all->ber, col, row);
			mlx_put_image_to_window(all->wi.mlx, all->wi.win,
				elem_at(&all->els, c), col * all->els.comp[0].img_width,
				row * all->els.comp[0].img_height);
			++col;
		}
		++row;
	}
}

int	win_init(t_all *all)
{
	all->wi.win = mlx_new_window(all->wi.mlx,
			all->ber.cols * all->els.comp[0].img_width,
			all->ber.rows * all->els.comp[0].img_height, "Solong");
	if (!all->wi.win)
		return (0);
	return (1);
}

int	win_key_init(int keycode, t_all *all)
{
	if (XK_Escape == keycode)
		mlx_loop_end(all->wi.mlx);
	if (XK_A == keycode || XK_a == keycode || XK_Left == keycode)
		win_move_p(all, -1, 0, 'o');
	if (XK_D == keycode || XK_d == keycode || XK_Right == keycode)
		win_move_p(all, +1, 0, 'e');
	if (XK_S == keycode || XK_s == keycode || XK_Down == keycode)
		win_move_p(all, 0, 1, 's');
	if (XK_W == keycode || XK_w == keycode || XK_Up == keycode)
		win_move_p(all, 0, -1, 'n');
	return (0);
}

void	win_move_anim(t_all *all, int col_off, int row_off, char c)
{
	char	fname[15];
	int		i;
	void	*img;
	int		tmp;

	my_strcpy(fname, "img/  .xpm");
	fname[4] = c;
	i = 0;
	while (5 > i)
	{
		if (2 == i)
			win_update_p_col_row(all, col_off, row_off);
		fname[5] = (char)(i + '0');
		img = mlx_xpm_file_to_image(all->wi.mlx, fname, &tmp, &tmp);
		mlx_put_image_to_window(all->wi.mlx, all->wi.win, img,
			all->ber.p_col * all->els.comp[0].img_width,
			all->ber.p_row * all->els.comp[0].img_height);
		if (i != 2)
			usleep(80000);
		i++;
		mlx_destroy_image(all->wi.mlx, img);
	}
	usleep(80000);
}
