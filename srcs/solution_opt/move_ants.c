/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:05:54 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/06 14:06:02 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		assign_new_values(t_map *map, int i, int *if_only)
{
	t_list		*tmp;

	if (map->ant_farm[i]->path->waitlist == 0)
	{
		if (*if_only == 0)
			ft_printf(" ");
		*if_only = 0;
		tmp = map->ant_farm[i]->path->next;
		free(map->ant_farm[i]->path);
		map->ant_farm[i]->path = tmp;
		map->ant_farm[i]->room_index = map->ant_farm[i]->path->index;
		ft_printf("L%d-%s", i + 1, \
		return_name_from_index(map, map->ant_farm[i]->room_index));
	}
	else
		--map->ant_farm[i]->path->waitlist;
}

void		move_ants(t_map *map)
{
	int		i;
	int		if_only;
	t_list	*tmp;

	i = 0;
	if_only = 1;
	while (map->ant_farm[i])
	{
		tmp = map->ant_farm[i]->path;
		if (map->ant_farm[i]->path != NULL && \
			map->ant_farm[i]->room_index != map->end_index)
			assign_new_values(map, i, &if_only);
		++i;
	}
	ft_printf("\n");
}
