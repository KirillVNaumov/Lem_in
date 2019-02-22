# include "lem_in.h"

void            print_connections(t_map *map)
{
    t_rooms     *tmp_rooms;
    t_links     *tmp_links;

    tmp_rooms = map->rooms;
    ft_printf("PRINT_CONNECTIONS\n");
    ft_printf("---------------------------------\n");
    while (tmp_rooms)
    {
        ft_printf("%s:\n", tmp_rooms->name);
        tmp_links = tmp_rooms->links;
        while (tmp_links)
        {
            ft_printf(" - %d - [%s]\n", tmp_links->index, tmp_links->name);
            tmp_links = tmp_links->next;
        }
        ft_printf("\n");
        tmp_rooms = tmp_rooms->next;
    }
    ft_printf("---------------------------------\n");
}
