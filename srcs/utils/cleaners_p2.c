/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:09:57 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/06 13:46:12 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clean_links(t_links *links)
{
	if (links->next)
		clean_links(links->next);
	free(links->name);
	free(links);
}

void	clean_rooms(t_rooms *rooms)
{
	if (rooms->next)
		clean_rooms(rooms->next);
	free(rooms->name);
	free(rooms->links_array);
	clean_links(rooms->links);
	free(rooms);
}

void	clean_moves(t_moves *moves)
{
	if (moves->next)
		clean_moves(moves->next);
	free(moves->room_presence);
	free(moves);
}

void	free_all_data(t_map *map, t_path *path)
{
	free(map->start);
	free(map->end);
	clean_graph(&map->graph, number_of_vertices(map));
	clean_moves(map->moves);
	clean_rooms(map->rooms);
	clean_path(path);
	clean_ants(map->ant_farm);
}
