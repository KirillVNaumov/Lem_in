#include "lem_in.h"

t_moves         *add_moves(t_moves *graph, t_map *map)
{
	t_moves	*new;
	t_moves	*begin;
    int     i;

    i = 0;
	if (!graph)
	{
		graph = (t_moves *)malloc(sizeof(t_moves));
		graph->room_presence = (int *)malloc(sizeof(int) * map->length);
        while (i < map->length)
            graph->room_presence[i++] = 0;
		graph->next = NULL;
		return (graph);
	}
	begin = graph;
	new = (t_moves *)malloc(sizeof(t_moves));
    new->room_presence = (int *)malloc(sizeof(int) * map->length);
    while (i < map->length)
        new->room_presence[i++] = 0;
    new->next = NULL;
	while (graph->next)
		graph = graph->next;
	graph->next = new;
	return (begin);
}