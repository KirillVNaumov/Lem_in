#include "lem_in.h"

void		assign_new_values(t_map *map, int i, int *if_only)
{
	if (map->ant_farm[i]->path->waitlist == 0)
	{
		if (*if_only == 0)
			ft_printf(" ");
		*if_only = 0;
		map->ant_farm[i]->path = map->ant_farm[i]->path->next;
		map->ant_farm[i]->room_index = map->ant_farm[i]->path->index;
		ft_printf("L%d-%s", i + 1, return_name_from_index(map, map->ant_farm[i]->room_index));
	}
	else
		--map->ant_farm[i]->path->waitlist;
}

void		move_ants(t_map *map)
{
	int		i;
	int		if_only;

	i = 0;
	if_only = 1;
	while (map->ant_farm[i])
	{
		if (map->ant_farm[i]->path != NULL && \
			map->ant_farm[i]->room_index != map->end_index)
			assign_new_values(map, i, &if_only);
		++i;
	}
	ft_printf("\n");
}
