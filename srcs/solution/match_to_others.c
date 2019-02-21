#include "lem_in.h"

int         check_with_ant(t_list **path, t_map *map, int index, int waitlist)
{
    t_list  *ant_path_tmp;
    t_list  *path_tmp;
    t_list  *prev_room;
    int     counter;

    ant_path_tmp = map->ant_farm[index]->path->next;
    path_tmp = (*path)->next;
    prev_room = (*path);
    counter = 0;
    waitlist = 1;
    // while (counter++ != (waitlist - map->ant_farm[index]->waitlist) && ant_path_tmp)
    //     ant_path_tmp = ant_path_tmp->next;
    // ft_printf("Ant that is being checked == %d\n", index + 1);
    while (path_tmp && ant_path_tmp)
    {    
        // ft_printf("Ant %i, ant node index = %d, path nove index = %d\n", index + 1, ant_path_tmp->index, path_tmp->index);
        if (path_tmp->index == ant_path_tmp->index)
        {
            if (ant_path_tmp->index != map->end_index && ant_path_tmp->index != map->start_index)
            {
                // print_list(map->ant_farm[index]->path);
                // print_list(*path);
                if (prev_room->index == path_tmp->index)
                    return (-2);
                prev_room = add_next_list(prev_room, prev_room->index, path_tmp);
                // ft_printf("ADDING A ROOM!!!\n");
                // print_list(*path);
                // ft_printf("CRASHED\n");
                return (-1);
            }
        }
        prev_room = prev_room->next;
        ant_path_tmp = ant_path_tmp->next;
        path_tmp = path_tmp->next;
    }
    return (1);
}

t_list      *match_to_others(t_list *path, t_map *map, int index, int waitlist)
{
    int     i;
    int     answer;

    i = 0;
    // ft_printf("\nCHECKINT_ANT %d:\n", index + 1);
    // print_list(path);
    // ft_printf("\n");
    // if (index == 13)
    // {
    //     print_list(path);
    //     sleep(1);
    // }
    while (i != index)
    {
        // ft_printf("     Checking ant No%d\n", i + 1);
        // if (index == 13)
        //     sleep(1);
        // if (index == 13 && i == 11)
        // {
        //     print_list(map->ant_farm[i]->path);
        //     sleep(10);
        // }
        answer = check_with_ant(&path, map, i, waitlist);
        if (answer == -1)
            i = -1;
        if (answer == -2)
        {
            path->index = -1;
            return (path);
        }
        ++i;
    }
    return (path);
}
