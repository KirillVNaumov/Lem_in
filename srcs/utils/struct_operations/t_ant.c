#include "lem_in.h"

void        create_ant_farm(t_map *map)
{
    int     i;

    map->ant_farm = (t_ant **)malloc(sizeof(t_ant *) * map->number_of_ants + 1);
    i = 0;
    while (i < map->number_of_ants)
    {
        map->ant_farm[i] = (t_ant *)malloc(sizeof(t_ant ));
        map->ant_farm[i]->path = NULL;
        map->ant_farm[i]->waitlist = 0;
        map->ant_farm[i]->room_index = map->start_index;
        ++i;
    }
    map->ant_farm[i] = NULL;
}