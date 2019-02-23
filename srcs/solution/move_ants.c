/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:43:48 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:44:52 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		assign_new_values(t_map *map, int *if_only, int *if_printed, int i)
{
	t_list	*tmp;
	int		counter;
	int		if_equal;

	counter = 0;
	if_equal = 0;
	tmp = map->ant_farm[i]->path;
	while (counter++ != map->ant_farm[i]->rooms_passed)
		tmp = tmp->next;
	if (map->ant_farm[i]->room_index == tmp->next->index)
		if_equal = 1;
	map->ant_farm[i]->room_index = tmp->next->index;
	++map->ant_farm[i]->rooms_passed;
	if (if_equal == 0)
	{
		if (*if_only == 0)
			ft_printf(" ");
		*if_only = 0;
		*if_printed = 1;
		ft_printf("L%d-%s", i + 1,\
		return_name_from_index(map, map->ant_farm[i]->room_index));
	}
}

void		move_ants(t_map *map)
{
	int	i;
	int	if_only;
	int	if_printed;

	i = 0;
	if_only = 1;
	if_printed = 0;
	while (map->ant_farm[i])
	{
		if (map->ant_farm[i]->path != NULL && \
			map->ant_farm[i]->room_index != map->end_index)
			assign_new_values(map, &if_only, &if_printed, i);
		++i;
	}
	if (if_printed == 1)
		ft_printf("\n");
}
