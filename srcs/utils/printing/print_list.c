# include "lem_in.h"

void         print_list(t_list *list)
{
    while (list)
    {
        ft_printf("[%d]", list->index);
        if (list->next)
            ft_printf("->");
        list = list->next;
    }
    ft_printf("\n\n");
}