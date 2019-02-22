#include "lem_in.h"

void         print_graph_from_map(t_map *map)
{
    int     length = number_of_vertices(map);
    t_rooms *tmp_rooms;

    tmp_rooms = map->rooms;
    while (tmp_rooms)
    {
        ft_printf("%d - [%s]\n", tmp_rooms->index, tmp_rooms->name);
        tmp_rooms = tmp_rooms->next;
    }
    ft_printf("\n");
    print_graph(map->graph, length);
}

void         print_graph(int **graph, int size)
{
    int     i = 0;
    int     j = 0;

    ft_printf("PRINT_GRAPH\n");
    ft_printf("---------------------------------\n");
    ft_printf("    ");
    while (i < size)
        ft_printf("%d ", i++);
    ft_printf("\n\n");
    i = 0;
    while (i < size)
    {
        j = 0;
        ft_printf("%d   ", i);
        while (j < size)
        {
            if (graph[i][j] == 1)
                ft_printf("%s%d ", CRED, graph[i][j]);
            if (graph[i][j] == 0)
                ft_printf("%s%d ", CBLUE, graph[i][j]);
            ++j;
        }
        ft_printf("%s\n", CWHITE);
        ++i;
    }
    ft_printf("---------------------------------\n\n");
}