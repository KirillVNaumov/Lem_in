# include "lem_in.h"

int         check_if_room(char *line)
{
    int     i;

    if (line[0] == 'L')
        return (-1);
    i = 0;
    while (line[i] && line[i] > ' ')
        ++i;
    if (line[i] != ' ' || line[0] <= ' ')
        return (-1);
    ++i;
    while (line[i] && line[i] >= '0' && line[i] <= '9')
        ++i;
    if (line[i] != ' ')
        return (-1);
    ++i;
    while (line[i] && line[i] >= '0' && line[i] <= '9')
        ++i;
    if (line[i] != '\0')
        return (-1);
    return (1);
}

int         check_if_link(t_map *map, char *line)
{
    
    return (0);
}

int         check_room_existence(t_map *map, char *room)
{
    t_rooms     *tmp;

    tmp = map->rooms;
    while (tmp)
    {
        if (!ft_strcmp(tmp->name, room))
            return (1);
        tmp = tmp->next;
    }
    return (-1);
}

int         check_link_exictence(t_map *map, char *room, char *link)
{
    t_rooms     *tmp;

    tmp = map->rooms;
    while (tmp)
    {
        if (!ft_strcmp(tmp->name, room))
        {
            while (tmp->links)
            {
                if (!ft_strcmp(tmp->links->name, link))
                    return (1);
                tmp->links = tmp->links->next;
            }
            return (-1);
        }
        tmp = tmp->next;
    }
    return (-1);
}