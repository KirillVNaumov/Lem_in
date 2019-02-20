#include "lem_in.h"

void        algorithm(int *index, int **graph, t_path **path, t_list *list)
{
    int     i;
    int     tmp;

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
            // print_graph(graph, index[2]);
            tmp = index[0];
            index[0] = i;
            algorithm(index, graph, path, list);
            index[0] = tmp;
            graph[i][index[0]] = 1;
            graph[index[0]][i] = 1;
            list = delete_list(list);
        }
        ++i;
    }
}
