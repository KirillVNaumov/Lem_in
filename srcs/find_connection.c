# include "lem_in.h"

int         find_connection(t_map *map)
{
    while (map->rooms)
    {
        ft_printf("%s:\n", map->rooms->name);
        while (map->rooms->links)
        {
            ft_printf(" - %s\n", map->rooms->links->name);
            map->rooms->links = map->rooms->links->next;
        }
        ft_printf("\n");
        map->rooms = map->rooms->next;
    }
    return (1);
}