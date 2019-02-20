#include "lem_in.h"

t_list      *find_best_path(t_path *path, t_map *map, int i)
{
    int     best_tempi;
    t_path  *best_choice;

    best_tempi = 2147483647;
    best_choice = NULL;
    while (path)
    {
        if (best_tempi > path->length + path->waitlist)
        {
            best_tempi = path->length + path->waitlist;
            best_choice = path;
        }
        path = path->next;
    }
    map->ant_farm[i]->waitlist = best_choice->waitlist;
    if (best_choice->length != 2)
        ++best_choice->waitlist;
    return (copy_list(best_choice->path));
}

void        assign_paths(t_map *map, t_path *path)
{
    int     i;

    i = 0;
    while (map->ant_farm[i])
    {
        map->ant_farm[i]->path = find_best_path(path, map, i);
        ++i;
    }
}