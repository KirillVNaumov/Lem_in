#include "lem_in.h"

int         no_repeats(t_list *list, int to_find)
{
    while (list)
    {
        if (list->index == to_find)
            return (0);
        list = list->next;
    }
    return (1);
}

void        algorithm(int *index, int **graph, t_path **path, t_list *list)
{
    int     i;
    int     tmp;

    // if (no_repeats(list, index[0]) == 0)
    //     return ;
    list = add_list(list, index[0]);
    // print_list(list);
    if (index[0] == index[1])
    {
        (*path) = add_path(*path, list);
        return ;
    }
    i = 0;
    while (i < index[2])
    {
        if (graph[index[0]][i] == 1)
        {
            graph[i][index[0]] = 0;
            graph[index[0]][i] = 0;
            print_graph(graph, index[2]);
            tmp = index[0];
            index[0] = i;
            // if (no_repeats(list, index[0]) == 1)
            algorithm(index, graph, path, list);
            index[0] = tmp;
            graph[i][index[0]] = 1;
            graph[index[0]][i] = 1;
            list = delete_list(list);
        }
        ++i;
    }
}
