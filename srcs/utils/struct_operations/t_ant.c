/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ant.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:25:17 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:25:38 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		create_ant_farm(t_map *map)
{
	int	i;

	map->ant_farm = (t_ant **)malloc(sizeof(t_ant *)\
	* (map->number_of_ants + 1));
	i = 0;
	while (i < map->number_of_ants)
	{
		map->ant_farm[i] = (t_ant *)malloc(sizeof(t_ant ));
		map->ant_farm[i]->path = NULL;
		map->ant_farm[i]->rooms_passed = 0;
		map->ant_farm[i]->room_index = map->start_index;
		++i;
	}
	map->ant_farm[i] = NULL;
}
