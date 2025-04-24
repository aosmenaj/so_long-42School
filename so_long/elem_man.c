/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:41:17 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:41:18 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elem_man.h"
#include "utility.h"
#include <unistd.h>

void	*elem_at(t_elem *el, char c)
{
	int	i;

	i = 0;
	while (6 > i)
	{
		if (c == el->comp[i].i_am)
			return (el->comp[i].img);
		++i;
	}
	return (NULL);
}

void	elem_init(t_elem *el)
{
	int	i;

	i = 0;
	while (6 > i)
	{
		el->comp[i].img = NULL;
		el->comp[i].img_width = 0;
		el->comp[i].img_height = 0;
		++i;
	}
	el->steps_count = 0;
	my_strcpy(el->steps, "\rYour moves so far: 0");
}
