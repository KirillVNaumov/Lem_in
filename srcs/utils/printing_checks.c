# include "lem_in.h"

int         print_connections(t_map *map)
{
    ft_printf("PRINT_CONNECTIONS\n");
    ft_printf("---------------------------------\n");
    while (map->rooms)
    {
        ft_printf("%s:\n", map->rooms->name);
        while (map->rooms->links)
        {
            ft_printf(" - %d - [%s]\n", map->rooms->links->index, map->rooms->links->name);
            map->rooms->links = map->rooms->links->next;
        }
        ft_printf("\n");
        map->rooms = map->rooms->next;
    }
    ft_printf("---------------------------------\n");
    return (1);
}

int         print_graph_from_map(t_map *map)
{
    int     length = number_of_vertices(map);
    t_rooms *tmp_rooms;

    tmp_rooms = map->rooms;
    while (tmp_rooms)
    {
        ft_printf("%d - [%s]\n", tmp_rooms->index, tmp_rooms->name);
        tmp_rooms = tmp_rooms->next;
    }
    print_graph(map->graph, length);
    return (1);
}

int         print_graph(int **graph, int size)
{
    int     i = 0;
    int     j = 0;

    ft_printf("PRINT_GRAPH\n");
    ft_printf("---------------------------------\n");
    ft_printf("    ");
    while (i < size)
        ft_printf("%d ", i++);
    ft_printf("\n\n");
    i = 0;
    while (i < size)
    {
        j = 0;
        ft_printf("%d   ", i);
        while (j < size)
        {
            if (graph[i][j] == 1)
                ft_printf("%s%d ", CRED, graph[i][j]);
            if (graph[i][j] == 0)
                ft_printf("%s%d ", CBLUE, graph[i][j]);
            ++j;
        }
        ft_printf("%s\n", CWHITE);
        ++i;
    }
    ft_printf("---------------------------------\n");
    return (1);
}

int         print_list(t_list *list)
{
    ft_printf("PRINT_LIST\n\n");
    // ft_printf("---------------------------------\n");
    while (list)
    {
        ft_printf("[%d]", list->index);
        if (list->next)
            ft_printf("->");
        list = list->next;
    }
    ft_printf("\n\n");
    // ft_printf("---------------------------------\n");
    return (1);
}

int         print_path(t_path *path)
{
    ft_printf("PRINT_PATH\n");
    ft_printf("---------------------------------\n");
    while (path)
    {
        print_list(path->path);
        path = path->next;
    }
    ft_printf("---------------------------------\n");
    return (1);
}