/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:41:08 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:41:09 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disp_man.h"
#include "mlx.h"
#include "utility.h"
#include <stdlib.h>

void	disp_destroy_comps(t_disp *disp, t_elem *el)
{
	int		i;
	void	*img;

	i = 0;
	while (6 > i)
	{
		img = el->comp[i].img;
		if (img)
			mlx_destroy_image(disp->mlx, img);
		++i;
	}
}

int	disp_init_envir(t_disp *disp)
{
	disp->mlx = mlx_init();
	if (!disp->mlx)
		return (0);
	mlx_get_screen_size(disp->mlx, &disp->screen_width, &disp->screen_height);
	return (1);
}

int	disp_init_or_die(t_disp *disp, t_elem *el)
{
	disp->mlx = NULL;
	if (!disp_init_envir(disp))
		return (0);
	if (!disp->mlx)
		return (0);
	elem_init(el);
	if (!disp_load_basic_imgs(disp, el))
	{
		disp_destroy_comps(disp, el);
		return (0);
	}
	return (1);
}

int	disp_load_basic_imgs(t_disp *disp, t_elem *el)
{
	char const	bers[] = "01CEPN";
	char		fname[11];
	int			i;
	t_comp		*comp;

	my_strcpy(fname, "img/ .xpm");
	if (!disp || !disp->mlx)
		return (0);
	i = 0;
	while (5 >= i)
	{
		comp = &el->comp[i];
		comp->i_am = bers[i];
		fname[4] = bers[i];
		if (!file_exists(fname))
		{
			display_error("Cannot find the requested image.\n");
			disp_destroy_comps(disp, el);
			return (0);
		}
		comp->img = mlx_xpm_file_to_image(disp->mlx, fname,
				&comp->img_width, &comp->img_height);
		++i;
	}
	return (1);
}

int	disp_ondestroy(void *mlx)
{
	mlx_loop_end(mlx);
	return (1);
}
