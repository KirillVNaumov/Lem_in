#include "lem_in.h"

void		update_moves(t_map *map, int i)
{
	t_list	*tmp_list;
	t_moves	*tmp_moves;

	tmp_list = map->ant_farm[i]->path->next;
	tmp_moves = map->moves;
	while (tmp_moves && tmp_list)
	{
		tmp_moves->room_presence[tmp_list->index] = 1;
		tmp_list = tmp_list->next;
		tmp_moves = tmp_moves->next;
	}
	if (!tmp_moves && tmp_list)
	{
		map->moves = add_moves(map->moves, map);
		update_moves(map, i);
	}
}