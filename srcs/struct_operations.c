# include "lem_in.h" 

t_rooms     *add_room(t_rooms *rooms, char *name, int x, int y)
{
    t_rooms     *new;
    t_rooms     *begin;

    if (!rooms)
    {
        rooms = (t_rooms *)malloc(sizeof(t_rooms *));
        rooms->links = (t_links *)malloc(sizeof(t_links *));
        rooms->name = ft_strdup(name);
        rooms->x = x;
        rooms->y = y;
        rooms->next = NULL;
        return (rooms);
    }
    begin = rooms;
    new = (t_rooms *)malloc(sizeof(t_rooms *));
    new->links = (t_links *)malloc(sizeof(t_links *));
    new->name = ft_strdup(name);
    new->x = x;
    new->y = y;
    new->next = NULL;
    while (rooms->next)
        rooms = rooms->next;
    rooms->next = new;
    return (rooms);
}

t_links     *add_link(t_links *links, char *name)
{
    t_links     *new;
    t_links     *begin;

    if (!links)
    {
        links = (t_links *)malloc(sizeof(t_links *));
        links->name = ft_strdup(name);
        links->next = NULL;
        return (links);
    }
    begin = links;
    new = (t_links *)malloc(sizeof(t_links *));
    new->name = ft_strdup(name);
    new->next = NULL;
    while (links->next)
        links = links->next;
    links->next = new;
    return (links);
}