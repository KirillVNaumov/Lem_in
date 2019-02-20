#include "lem_in.h"

void        assign_new_values(t_map *map, int *if_only, int i)
{
    t_list  *tmp;
    int     counter;

    counter = 0;
    if (map->ant_farm[i]->waitlist == 0)
    {
        tmp = map->ant_farm[i]->path;
        while (counter++ != map->ant_farm[i]->rooms_passed)
            tmp = tmp->next;
        map->ant_farm[i]->room_index = tmp->next->index;
        ++map->ant_farm[i]->rooms_passed;
        if (*if_only == 0)
            ft_printf(" ");
        *if_only = 0;
        ft_printf("L%d-%s", i + 1, return_name_from_index(map, map->ant_farm[i]->room_index));
    }
    else
        --map->ant_farm[i]->waitlist;
}

void        move_ants(t_map *map)
{
    int     i;
    int     if_only;

    i = 0;
    if_only = 1;
    while (map->ant_farm[i])
    {
        if (map->ant_farm[i]->path != NULL && \
            map->ant_farm[i]->room_index != map->end_index)
            assign_new_values(map, &if_only, i);
        ++i;
    }
    ft_printf("\n");
}