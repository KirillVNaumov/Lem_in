#include "lem_in.h"

char        *return_name_from_index(t_map *map, int index)
{
    t_rooms *tmp;

    tmp = map->rooms;
    while (tmp)
    {
        if (tmp->index == index)
            return (tmp->name);
        tmp = tmp->next;
    }
    return ("NULL");
}