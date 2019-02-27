#include "lem_in.h"

t_list	*find_best_path(t_path *path, t_map *map)
{
	int		best_tempi;
	t_list	*best_path;
	t_list	*tmp;

	best_tempi = 2147483647;
	best_path = NULL;
	print_path(path);
	while (path)
	{
		tmp = prepare_new_path(map, path->path);
		print_list(tmp);
		if (best_tempi > size_list(tmp))
		{
			best_tempi = size_list(tmp);
			best_path = tmp;
		}
		path = path->next;
	}
	return (copy_list(best_path));
}


void	assign_paths(t_map *map, t_path *path)
{
	int         i;

	i = 0;
    map->moves = NULL;
	while (map->ant_farm[i])
	{
		map->ant_farm[i]->path = find_best_path(path, map);
		update_moves(map, i);
		++i;
	}
}

