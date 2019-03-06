/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:11:35 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/06 14:15:38 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	update_moves(t_map *map, int i, t_list *tmp_list, t_moves *tmp_moves)
{
	int		index;

	tmp_list = map->ant_farm[i]->path;
	tmp_moves = map->moves;
	index = 0;
	while (tmp_list->waitlist - index++ > 0)
		if (tmp_moves)
			tmp_moves = tmp_moves->next;
	tmp_list = tmp_list->next;
	index = 0;
	while (tmp_moves && tmp_list)
	{
		if (tmp_list->index != map->end_index)
			tmp_moves->room_presence[tmp_list->index] = 1;
		if (tmp_list->waitlist - index == 0)
			tmp_list = tmp_list->next;
		else
			++index;
		tmp_moves = tmp_moves->next;
	}
	if (!tmp_moves && tmp_list)
	{
		map->moves = add_moves(map->moves, map);
		update_moves(map, i, NULL, NULL);
	}
}
