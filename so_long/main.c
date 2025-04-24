/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:41:32 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/04/22 19:41:40 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (2 != argc)
	{
		write(STDOUT_FILENO, "Error\nusage: so_long map.ber\n", 29);
		return (0);
	}
	return (sl_solong(argv[1]));
}
