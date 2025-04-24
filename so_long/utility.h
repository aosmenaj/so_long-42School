/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:42:51 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:42:52 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

void	display_error(char const *const s);
void	display_str(const char *const s);
void	display_str_nl(const char *const s);
int		file_exists(char const *const fname);
int		find_char_in_str(const char *const s, char c, int max);
void	my_atoi(int n, char *fill);
int		my_strcpy(char *dest, const char *const src);
void	my_strcpy_n(char *dest, char const *const src, int howmany);
int		my_strlen(char const *const s);
void	put_str_to_zero(char *s, int length);

#endif
