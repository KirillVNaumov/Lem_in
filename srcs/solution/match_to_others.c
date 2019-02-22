#include "lem_in.h"

int         check_with_ant(t_list **path, t_map *map, int index)
{
    t_list  *ant_path_tmp;
    t_list  *path_tmp;
    t_list  *prev_room;

    ant_path_tmp = map->ant_farm[index]->path->next;
    path_tmp = (*path)->next;
    prev_room = (*path);
    while (path_tmp && ant_path_tmp)
    {
        if (path_tmp->index == ant_path_tmp->index)
        {
            if (ant_path_tmp->index != map->end_index && ant_path_tmp->index != map->start_index)
            {
                if (prev_room->index == path_tmp->index)
                    return (-1);
                prev_room = add_next_list(prev_room, prev_room->index, path_tmp);
                return (0);
            }
        }
        prev_room = prev_room->next;
        ant_path_tmp = ant_path_tmp->next;
        path_tmp = path_tmp->next;
    }
    return (1);
}

t_list      *match_to_others(t_list *path, t_map *map, int index)
{
    int     i;
    int     answer;

    i = 0;
    while (i != index)
    {
        answer = check_with_ant(&path, map, i);
        if (answer == 0)
            i = -1;
        if (answer == -1)
        {
            path->index = -1;
            return (path);
        }
        ++i;
    }
    return (path);
}
