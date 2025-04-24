/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:40:57 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:40:58 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ber_man.h"
#include "utility.h"
#include <stdlib.h>

int	ber_double(t_bm *bm)
{
	char	*tmp_cs;
	int		tmp_cpy;

	tmp_cpy = bm->cpy * 2;
	tmp_cs = malloc(sizeof(char) * (size_t)tmp_cpy);
	if (!tmp_cs)
		return (0);
	put_str_to_zero(tmp_cs, tmp_cpy);
	my_strcpy_n(tmp_cs, bm->str, bm->size);
	free(bm->str);
	bm->str = tmp_cs;
	bm->cpy = tmp_cpy;
	return (1);
}

void	ber_free_str(t_bm *bm)
{
	if (bm)
	{
		if (bm->str)
		{
			free(bm->str);
			bm->str = NULL;
		}
		bm->cpy = 0;
		bm->size = 0;
	}
}

int	ber_init_or_die(t_bm *bm, int capacity)
{
	if (!capacity)
		capacity = DEFAULT_BER_SIZE;
	bm->cpy = capacity;
	bm->str = malloc(sizeof(char) * (size_t)bm->cpy);
	if (!bm->str)
		return (0);
	ber_set_str_to_zero(bm);
	bm->coll_num = 0;
	bm->exit_num = 0;
	bm->p_col = 0;
	bm->p_row = 0;
	return (1);
}

void	ber_set_str_to_zero(t_bm *bm)
{
	put_str_to_zero(bm->str, bm->cpy);
	bm->cols = 0;
	bm->rows = 0;
	bm->size = 0;
}

int	ber_shrink_to_fit(t_bm *bm)
{
	char	*tmp_cs;

	tmp_cs = malloc(sizeof(char) * (size_t)bm->size);
	if (!tmp_cs)
		return (0);
	my_strcpy_n(tmp_cs, bm->str, bm->size);
	free(bm->str);
	bm->str = tmp_cs;
	return (1);
}
