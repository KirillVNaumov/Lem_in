/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:09:57 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:10:24 by amelikia         ###   ########.fr       */
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
	clean_links(rooms->links);
	free(rooms);
}

void	free_all_data(t_map *map, t_path *path)
{
	free(map->start);
	free(map->end);
	clean_graph(&map->graph, number_of_vertices(map));
	clean_rooms(map->rooms);
	clean_path(path);
	clean_ants(map->ant_farm);
}
