#include "lem_in.h"

t_graph         *add_graph(t_graph *graph, t_map *map)
{
	t_graph	*new;
	t_graph	*begin;
    int     i;

    i = 0;
	if (!graph)
	{
		graph = (t_graph *)malloc(sizeof(t_graph));
		graph->room_presence = (int *)malloc(sizeof(int) * map->length);
        while (i < map->length)
            graph->room_presence[i++] = 0;
		graph->next = NULL;
		return (graph);
	}
	begin = graph;
	new = (t_graph *)malloc(sizeof(t_graph));
    new->room_presence = (int *)malloc(sizeof(int) * map->length);
    while (i < map->length)
        new->room_presence[i++] = 0;
    new->next = NULL;
	while (graph->next)
		graph = graph->next;
	graph->next = new;
	return (begin);
}