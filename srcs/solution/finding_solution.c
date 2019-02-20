#include "lem_in.h"

int         if_solved(t_map *map)
{
    int     i;

    i = 0;
    while (map->ant_farm[i])
    {
        if (map->ant_farm[i]->room_index != map->end_index)
            return (1);
        ++i;
    }
    return (0);
}

void        find_solution(t_map *map, t_path **path)
{  
    int     number_of_moves;

    assign_paths(map, *path);
    print_ant_farm(map);
    number_of_moves = 0;
    while (if_solved(map))
    {
        move_ants(map);
        ++number_of_moves;
    }
    ft_printf("Number of moves: %d\n", number_of_moves);
}