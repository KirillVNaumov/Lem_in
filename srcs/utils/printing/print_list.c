# include "lem_in.h"

void         print_list(t_list *list)
{
    ft_printf("PRINT_LIST\n\n");
    while (list)
    {
        ft_printf("[%d]", list->index);
        if (list->next)
            ft_printf("->");
        list = list->next;
    }
    ft_printf("\n\n");
}