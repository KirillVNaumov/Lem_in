# include "lem_in.h"

int         number_of_vertices(t_map *map)
{
    t_rooms     *tmp;
    int         i;

    i = 0;
    tmp = map->rooms;
    while (tmp)
    {
        ++i;
        tmp = tmp->next;
    }
    return (i);
}

void        initializing_graph(t_map *map)
{
    int     i;
    int     j;
    int     length;

    length = number_of_vertices(map);
    map->graph = (int **)malloc(sizeof(int *) * length + 1);
    i = 0;
    while (i < length)
    {
        j = 0;
        map->graph[i] = (int *)malloc(sizeof(int) * length + 1);
        while (j < length)
            map->graph[i][j++] = 0;
        ++i;
    }
}

void        creating_graph(t_map *map)
{
    int     i;
    int     j;
    int     length;

    length = number_of_vertices(map);
    initializing_graph(map);
    i = 0;
    while (i < length)
    {
        j = 0;
        while (j < length)
        {
            if (if_connected(map, i, j))
                map->graph[i][j] = 1;
            ++j;
        }
        ++i;
    }
}
