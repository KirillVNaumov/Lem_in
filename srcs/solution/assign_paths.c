#include "lem_in.h"

t_list      *find_best_path(t_path *path, t_map *map, int i)
{
    int     best_tempi;
    t_path  *best_choice;
    t_list  *tmp;
    t_list  *final_list;

    best_tempi = 2147483647;
    best_choice = NULL;
    while (path)
    {
        tmp = match_to_others(copy_list(path->path), map, i);
        if (best_tempi > size_list(tmp) + path->waitlist)
        {
            best_tempi = size_list(tmp) + path->waitlist;
            final_list = copy_list(tmp);
            best_choice = path;
        }
        path = path->next;
    }
    if (best_choice->length != 2)
        ++best_choice->waitlist;
    return (final_list);
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