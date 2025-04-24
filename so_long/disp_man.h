/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_man.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:41:13 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:41:14 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISP_MAN_H
# define DISP_MAN_H

# include "elem_man.h"

struct s_display_info
{
	void	*mlx;
	int		screen_height;
	int		screen_width;
	void	*win;
};

typedef struct s_display_info	t_disp;

int		disp_anim_block_set(t_disp *disp, void **block, char c);
void	disp_destroy_comps(t_disp *disp, t_elem *el);
int		disp_init_envir(t_disp *disp);
int		disp_init_or_die(t_disp *disp, t_elem *el);
int		disp_load_basic_imgs(t_disp *disp, t_elem *el);
int		disp_load_animations(t_disp *disp);
int		disp_ondestroy(void *mlx);

#endif
