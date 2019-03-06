/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:05:15 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/06 14:05:16 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
