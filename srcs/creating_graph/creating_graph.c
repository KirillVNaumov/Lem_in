#include "lem_in.h"

int		number_of_vertices(t_map *map)
{
	t_rooms	*tmp;
	int		i;

	i = 0;
	tmp = map->rooms;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}

void	initializing_graph(t_map *map)
{
	int	i;
	int	j;

	map->graph = (int **)malloc(sizeof(int *) * map->length + 1);
	i = 0;
	while (i < map->length)
	{
		j = 0;
		map->graph[i] = (int *)malloc(sizeof(int) * map->length + 1);
		while (j < map->length)
			map->graph[i][j++] = 0;
		++i;
	}
}

void	creating_graph(t_map *map)
{
	t_rooms		*tmp_rooms;
	int	i;
	int	j;

	map->length = number_of_vertices(map);
	initializing_graph(map);
	create_links_array(map);
	tmp_rooms = map->rooms;
	i = 0;
	while (tmp_rooms)
	{
		j = 0;
		while (tmp_rooms->links_array[j] != -1)
			map->graph[i][tmp_rooms->links_array[j++]] = 1;
		tmp_rooms = tmp_rooms->next;
		++i;
	}
}