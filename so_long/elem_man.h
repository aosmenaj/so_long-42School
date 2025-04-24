/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_man.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:41:20 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/30 17:40:12 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEM_MAN_H
# define ELEM_MAN_H

# ifndef INT_MAX_DEF_LENGTH
#  define INT_MAX_DEF_LENGTH 30
# endif

struct s_component
{
	int		img_width;
	int		img_height;
	char	i_am;
	void	*img;
};

typedef struct s_component	t_comp;

struct s_elem
{
	t_comp	comp[6];
	char	steps[INT_MAX_DEF_LENGTH];
	int		steps_count;
};

typedef struct s_elem		t_elem;

void	*elem_at(t_elem *el, char c);
void	elem_init(t_elem *el);

#endif
