#include "lem_in.h"

int         find_index(t_map *map, char *name)
{
    t_rooms     *tmp;
    char        *tmp1;

    tmp1 = name;
    tmp = map->rooms;
    while (tmp)
    {
        if (!ft_strcmp(tmp->name, name))
            return (tmp->index);
        tmp = tmp->next;
    }
    return (-1);
}