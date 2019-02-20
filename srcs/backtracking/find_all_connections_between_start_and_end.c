#include "lem_in.h"

void    find_all_connections_between_start_and_end(t_map *map, t_path **path)
{
	int		*index;
	t_list	*list;

	list = NULL;
	index = (int *)malloc(sizeof(int) * 3);
	index[0] = map->start_index;
	index[1] = map->end_index;
	index[2] = number_of_vertices(map);
	algorithm(index, map->graph, path, list);
	*path = sort_path(*path);
	if (!(*path))
		error("There is no connection between start and end points");
}