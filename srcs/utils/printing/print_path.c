# include "lem_in.h"

void         print_path(t_path *path)
{
    t_list  *tmp;

    ft_printf("PRINT_PATH\n");
    ft_printf("---------------------------------\n");
    while (path)
    {
        tmp = path->path;
        print_list(tmp);
        path = path->next;
    }
    ft_printf("---------------------------------\n");
}