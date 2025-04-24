/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_man.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:27 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/30 19:19:03 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MAN_H
# define MAP_MAN_H

# include "ber_man.h"

int		map_add_char_or_row(t_bm *bm, int *length, int check, char c);
int		map_check_char(t_bm *bm, int *length, char c);
int		map_check_obj_occur(t_bm const *bm, char c);
int		map_copy(t_bm *dest, const t_bm *const source);
int		map_find_start(t_bm *bm);
int		map_find_exit(t_bm *bm);
void	map_flood_fill(t_bm *bm);
int		map_init_ber_data(t_bm *bm, const char *const fname);
int		map_init_or_die(t_bm *bm, const char *const fname);
int		map_is_char_valid(char c);
int		map_is_inside_map(t_bm *bm);
int		map_is_map_passable(t_bm const *orig);
int		map_is_map_valid(t_bm *bm);
int		map_open(char const *const fname);
int		map_read(t_bm *bm, int fd);
int		map_size_is_good(t_bm const *bm);
int		map_wall_are_solid(t_bm const *bm);
int		skip_char(t_bm *bm);

#endif
