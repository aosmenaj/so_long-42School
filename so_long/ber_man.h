/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_man.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:41:03 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:41:04 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BER_MAN_H
# define BER_MAN_H

struct s_ber_map
{
	int		cpy;
	int		coll_num;
	int		cols;
	int		exit_num;
	int		p_col;
	int		p_row;
	int		e_col;
	int		e_row;
	int		rows;
	int		size;
	char	*str;
};

typedef struct s_ber_map	t_bm;

# ifndef DEFAULT_BER_SIZE
#  define DEFAULT_BER_SIZE 15
# endif

int		ber_add_char(t_bm *bm, char c);
char	ber_at(t_bm const *bm, int col, int row);
int		ber_double(t_bm *bm);
void	ber_free_str(t_bm *bm);
int		ber_init_or_die(t_bm *bm, int capacity);
void	ber_set_str_to_zero(t_bm *bm);
int		ber_shrink_to_fit(t_bm *bm);

#endif
