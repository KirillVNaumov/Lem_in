#include "lem_in.h"

t_rooms     *add_room(t_rooms *rooms, char *name, int x, int y)
{
    t_rooms     *new;
    t_rooms     *begin;

    if (!rooms)
    {
        rooms = (t_rooms *)malloc(sizeof(t_rooms));
        rooms->x = x;
        rooms->y = y;
        rooms->name = ft_strdup(name);
        rooms->next = NULL;
        rooms->links = NULL;
        rooms->index = 0;
        return (rooms);
    }
    begin = rooms;
    new = (t_rooms *)malloc(sizeof(t_rooms));
    new->x = x;
    new->y = y;
    new->name = ft_strdup(name);
    new->next = NULL;
    new->links = NULL;
    while (rooms->next)
        rooms = rooms->next;
    rooms->next = new;
    new->index = rooms->index + 1;
    return (begin);
}