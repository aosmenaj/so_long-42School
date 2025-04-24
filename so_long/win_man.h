/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_man.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:43:03 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:43:04 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_MAN_H
# define WIN_MAN_H

# include "ber_man.h"
# include "disp_man.h"
# include "elem_man.h"

struct s_global_map
{
	struct s_ber_map		ber;
	struct s_elem			els;
	struct s_display_info	wi;
};
typedef struct s_global_map	t_all;

void	update_exit(t_all all);
void	win_els_paint(t_all *all);
int		win_init(t_all *all);
int		win_key_init(int keycode, t_all *all);
void	win_move_anim(t_all *all, int col_off, int row_off, char c);
int		win_move_checks(t_all *all, int col_off, int row_off);
void	win_move_p(t_all *all, int col_off, int row_off, char dir);
void	win_paint(t_all *all);
void	win_update_p_col_row(t_all *all, int col_off, int row_off);
void	clear_string(t_all *all);
void	game_over(t_all *all);
void	victory_achived(t_all *all);

#endif
