# include "lem_in.h"

void        print_ant_farm(t_map *map)
{
    int     i;

    i = 0;
    ft_printf("PRINT_ANT_FARM\n");
    ft_printf("---------------------------------\n");
    while (map->ant_farm[i])
    {
        ft_printf("ANT %d:\n***\n", i + 1);
        ft_printf("PATH = ");
        print_list(map->ant_farm[i]->path);
        ft_printf("***\n\n");
        ++i;
    }
    ft_printf("---------------------------------\n");
}