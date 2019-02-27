#include "lem_in.h"

void		print_moves(t_map *map)
{
	int			i;
	int			j;
	t_moves		*tmp;

	tmp = map->moves;
	ft_printf("      ");
	i = 0;
	while (i < map->length)
		ft_printf("[%d] ", i++);
	ft_printf("\n");
	i = 1;
	while (tmp)
	{
		ft_printf("%3d:  ", i);
		j = 0;
		while (j < map->length)
			ft_printf(" %d  ", tmp->room_presence[j++]);
		ft_printf("\n");
		++i;
		tmp = tmp->next;
	}
	ft_printf("\n");
}