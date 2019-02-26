#include "lem_in.h"

int         check_with_graph(t_list **path, t_map *map)
{
    while ((*path) && map->moves)
    {
        if (map->moves->room_presence[(*path)->index] == 1)
        {

            return (-1);
        }
        (*path) = (*path)->next;
        map->moves = map->moves->next;
    }
    return (1);
}

t_list      *prepare_new_path(t_map *map, t_list *path)
{
    while (check_with_graph(&path, map) == -1);
    return (path);
}
