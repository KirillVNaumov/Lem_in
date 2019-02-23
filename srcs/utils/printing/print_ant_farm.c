/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant_farm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:39:29 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:39:46 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_ant_farm(t_map *map)
{
	int	i;

	i = 0;
	ft_printf("PRINT_ANT_FARM\n");
	ft_printf("---------------------------------\n");
	while (map->ant_farm[i])
	{
		ft_printf("ANT %d:\n***\n\n", i + 1);
		ft_printf("PATH = \n");
		print_list(map->ant_farm[i]->path);
		ft_printf("***\n\n");
		++i;
	}
	ft_printf("---------------------------------\n");
}
