# include "lem_in.h"

void        read_number_of_ants(t_map *map, char *line)
{
    if (check_for_number(line) != -1 && check_for_integer(line) != -1)
        map->number_of_ants = ft_atoi(line);
    else
        error("No input for number of ants");
}

int         read_rooms(t_map *map, char *line)
{
    char    *name;
    int     x;
    int     y;
    int     i;

    if (check_if_room(line) == -1)
        return (1);
    i = 0;
    while (line[i] != ' ')
        ++i;
    name = ft_strsub(line, 0, i);
    ++i;
    x = ft_atoi(&line[i]);
    while (line[i] != ' ')
        ++i;
    ++i;
    y = ft_atoi(&line[i]);
    map->rooms = add_room(map->rooms, name, x, y);
    return (0);
}

int        read_links(t_map *map, char *line)
{
    if (check_if_link(map, line) == -1)
        return (1);
}

void        reading_input(t_map *map)
{
    char    *line;
    int     phase;

    phase = 0;
    while (get_next_line(0, &line))
    {
        if (line[0] == '#' && line[1] != '#')
            continue ;
        if (phase == 2)
            error("Unnecessary information");
        if (!map->number_of_ants)
            read_number_of_ants(map, line);
        else 
        {
            if (phase == 0)
                phase += read_rooms(map, line);
            if (phase == 1)
                phase += read_links(map, line);       
        }
    }
    if (phase != 2)
        error("Not enough information");
}