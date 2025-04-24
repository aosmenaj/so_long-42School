/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:40 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:42:41 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "win_man.h"

void	sl_clear_memory(t_all *all);
int		sl_solong(char const *const fname);
int		sl_get_valid_map(t_all *all, char const *const s);

#endif
