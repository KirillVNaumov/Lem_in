#include "lem_in.h"

t_list      *add_list(t_list *list, int index)
{
    t_list     *new;
    t_list     *begin;

    if (!list)
    {
        list = (t_list *)malloc(sizeof(t_list));
        list->index = index;
        list->next = NULL;
        return (list);
    }
    begin = list;
    new = (t_list *)malloc(sizeof(t_list));
    new->index = index;
    new->next = NULL;
    while (list->next)
        list = list->next;
    list->next = new;
    return (begin);
}

t_list      *delete_list(t_list *list)
{
    t_list  *new;

    new = list;
    if (!list->next)
        return (NULL);
    while (list->next->next)
        list = list->next;
    list->next = NULL;
    return (new);
}

t_list      *copy_list(t_list *list)
{
    t_list  *new;

    new = NULL;
    while (list)
    {
        new = add_list(new, list->index);
        list = list->next;
    }
    return (new);
}

int         size_list(t_list *list)
{
    int     i;
    
    i = 0;
    while (list)
    {
        ++i;
        list = list->next;
    }
    return (i);
}