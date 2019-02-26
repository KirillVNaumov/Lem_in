#include "lem_in.h"

t_list      *prepare_new_path(t_map *map, t_list *path, int index)
{
    int     i;

    t_map *tmp1;
    t_list  *tmp2;
    tmp1 = map;
    tmp2 = path;

    i = 0;
    while (i < index)
    {
		// if (check_with_ant(&path, map, i) == -1)
			// i = -1;
		++i;
    }
    return (path);
}
