#include "lem_in.h"

t_links     *add_link(t_links *links, char *name, int index)
{
    t_links     *new;
    t_links     *begin;

    if (!links)
    {
        links = (t_links *)malloc(sizeof(t_links));
        links->name = ft_strdup(name);
        links->index = index;
        links->next = NULL;
        return (links);
    }
    begin = links;
    new = (t_links *)malloc(sizeof(t_links));
    new->name = ft_strdup(name);
    new->index = index;
    new->next = NULL;
    while (links->next)
        links = links->next;
    links->next = new;
    return (begin);
}