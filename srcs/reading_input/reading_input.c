# include "lem_in.h"

int        read_number_of_ants(t_map *map, char *line)
{
    if (check_for_number(line) != -1 && check_for_integer(line) != -1)
        map->number_of_ants = ft_atoi(line);
    else
        error("No input for number of ants");
    return (1);
}

void        assign_start_and_end(t_map *map, int *start_end, char *name)
{
    if (*start_end == 1)
    {
        if (map->start)
            error("Start has already been assigned");
        map->start = ft_strdup(name);
    }
    if (*start_end == -1)
    {
        if (map->end)
            error("End has already been assigned");
        map->end = ft_strdup(name);
    }
}

int         read_rooms(t_map *map, char *line, int *start_end)
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
    assign_start_and_end(map, start_end, name);
    ++i;
    x = ft_atoi(&line[i]);
    while (line[i] != ' ')
        ++i;
    ++i;
    y = ft_atoi(&line[i]);
    if (check_room_existence(map, name) == 1)
        error("Redefinition of room");
    if (check_coordinates(map, x, y) == 1)
        error("Redefinition of coordinates");
    map->rooms = add_room(map->rooms, name, x, y);
    *start_end = 0;
    return (0);
}

void        adding_link_process(t_map *map, char *str1, char *str2)
{
    t_rooms *rooms;

    rooms = map->rooms;
    while (rooms)
    {
        if (!ft_strcmp(rooms->name, str1))
            rooms->links = add_link(rooms->links, str2, find_index(map, str2));
        if (!ft_strcmp(rooms->name, str2))
            rooms->links = add_link(rooms->links, str1, find_index(map, str1));
        rooms = rooms->next;
    }
}

int         read_links(t_map *map, char *line, int start_end)
{
    int     i;
    char    *str1;
    char    *str2;

    if (start_end != 0)
        error("Start/end is misplaced");
    i = 0;
    str1 = ft_strnew(1);
    str2 = ft_strnew(1);
    if (ft_strchr(line, '-') == NULL)
        return (1);
    while (line[i] != '-')
        str1 = add_char(str1, line[i++]);
    ++i;
    while (line[i] != '\0')
        str2 = add_char(str2, line[i++]);
    if (check_room_existence(map, str1) == -1 || check_room_existence(map, str2) == -1)
        error("Room doesn't exist");
    if (check_link_existence(map, str1, str2) == 1)
        error("Link already exists");
    adding_link_process(map, str1, str2);
    return (0);
}

int         check_for_hashtag(char *line, int *start_end, int phase)
{
    if (line[0] == '#')
    {
        if (line[1] == '#')
        {
            if (!ft_strcmp(&line[2], "start"))
                *start_end = 1;
            else if (!ft_strcmp(&line[2], "end"))
                *start_end = -1;
            else
                error("Incorrect use of double hashtag");
            if (phase != 1)
                error("Start/end is misplaced");
        }
        return (1);
    }
    return (0);
}

void        reading_input(t_map *map)
{
    char    *line;
    int     phase;
    int     start_end;

    phase = 0;
    start_end = 0;
    while (get_next_line(0, &line))
    {
        if (!ft_strcmp(line, "finish") || !ft_strcmp(line, ""))
            break ;
        if (check_for_hashtag(line, &start_end, phase) == 1)
            continue ;
        if (!map->number_of_ants)
            phase += read_number_of_ants(map, line);
        else 
        {
            if (phase == 1)
                phase += read_rooms(map, line, &start_end);
            if (phase == 2)
                phase += read_links(map, line, start_end);
            if (phase == 3)
                error("Wrong Input");
        }
    }
    if (!map->start)
        error("Start has not been assigned");
    if (!map->end)
        error("End has not been assigned");
    if (phase < 2)
        error("Not enough information");
}
