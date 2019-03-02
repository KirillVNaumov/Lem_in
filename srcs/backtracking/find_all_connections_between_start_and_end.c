/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_connections_between_start_and_end.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:25:27 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/01 16:20:29 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_all_connections_between_start_and_end(t_map *map, t_path **path)
{
	int		*index;
	t_list	*list;
	t_path		*tmp;

	list = NULL;
	index = (int *)malloc(sizeof(int) * 3);
	index[0] = map->start_index;
	index[1] = map->end_index;
	index[2] = number_of_vertices(map);
	print_graph_from_map(map);
	algorithm(index, map->graph, path, &list);
	list = delete_front_list(list);
	free(index);
	*path = sort_path(*path);
	if (!(*path))
		error("There is no connection between start and end points");
	tmp = *path;
	while (tmp)
	{
		tmp->path = reverse_list(tmp->path);
		tmp = tmp->next;
	}
}
