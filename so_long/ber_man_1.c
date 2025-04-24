/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_man_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:40:44 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:40:47 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ber_man.h"
#include "utility.h"
#include <stdlib.h>

int	ber_add_char(t_bm *bm, char c)
{
	if (bm->size == bm->cpy)
		if (!ber_double(bm))
			return (0);
	bm->str[bm->size] = c;
	++bm->size;
	return (1);
}

char	ber_at(t_bm const *bm, int col, int row)
{
	return (bm->str[row * bm->cols + col]);
}
