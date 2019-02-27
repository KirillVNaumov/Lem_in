/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_new_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:36:53 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/26 14:38:39 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_with_graph(t_list **path, t_map *map)
{
	t_list		*prev;
	t_list		*curr;

	prev = *path;
	curr = (*path)->next;
	while (curr && map->moves)
	{
		if (map->moves->room_presence[curr->index] == 1)
		{
			++prev->waitlist;
			return (-1);
		}
		curr = curr->next;
		prev = prev->next;
		map->moves = map->moves->next;
	}
	return (1);
}

t_list	*prepare_new_path(t_map *map, t_list *path)
{
	while (check_with_graph(&path, map) == -1)
		;
	return (path);
}
