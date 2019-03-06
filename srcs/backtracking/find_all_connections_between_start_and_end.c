/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_connections_between_start_and_end.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:25:27 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/06 15:21:02 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		if_last_room(t_list **nodestack, t_path **path, t_map *map, int vertex)
{
	*nodestack = add_back_list(*nodestack, map->current, 0);
	*nodestack = add_back_list(*nodestack, map->end_index, 0);
	*path = add_path(*path, *nodestack);
	*nodestack = delete_back_list(*nodestack);
	*nodestack = delete_back_list(*nodestack);
	if (vertex > 1000)
		return (-1);
	map->i++;
	return (1);
}

void	create_neighbors(t_list **neighbors,\
	t_list **visited, t_map *map)
{
	if (*neighbors)
		clean_list(*neighbors);
	*neighbors = get_neighbors(map->graph[map->current], map->length);
	while (map->i < size_list(*neighbors)\
	&& visited_before(*visited, get_i(*neighbors, map->i)) == 1)
		map->i++;
}

void	get_and_delete_last(t_list **nodestack,\
	t_list **indexstack, t_map *map)
{
	map->current = get_last_list(*nodestack);
	*nodestack = delete_back_list(*nodestack);
	map->i = get_last_list(*indexstack);
	*indexstack = delete_back_list(*indexstack);
}

void	add_last_room(t_lists *big_l, t_map *map)
{
	big_l->nodestack = add_back_list(big_l->nodestack, map->current, 0);
	big_l->indexstack = add_back_list(big_l->indexstack, map->i + 1, 0);
	big_l->visited = add_back_list(big_l->visited,\
		get_i(big_l->neighbors, map->i), 0);
	map->current = get_i(big_l->neighbors, map->i);
	map->i = 0;
}

void	find_all_connections_between_start_and_end(t_map *map,\
	t_path **path, int vertex)
{
	t_lists	big_l;

	bnull(&big_l);
	map->current = map->start_index;
	big_l.visited = add_back_list(big_l.visited, map->current, 0);
	while (1)
	{
		create_neighbors(&big_l.neighbors, &big_l.visited, map);
		if (map->i >= size_list(big_l.neighbors))
		{
			big_l.visited = delete_back_list(big_l.visited);
			if (size_list(big_l.nodestack) < 1)
				break ;
			get_and_delete_last(&big_l.nodestack, &big_l.indexstack, map);
		}
		else if (get_i(big_l.neighbors, map->i) == map->end_index)
		{
			if (if_last_room(&big_l.nodestack, path, map, vertex) == -1)
				break ;
		}
		else
			add_last_room(&big_l, map);
	}
	clear_used_data(&big_l);
}
