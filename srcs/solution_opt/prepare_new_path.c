/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_new_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:36:53 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/26 14:38:39 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_with_graph(t_list **path, t_map *map)
{
	t_list		*prev;
	t_list		*curr;
	t_moves		*tmp_moves;
	int			i;

	prev = *path;
	curr = (*path)->next;
	tmp_moves = map->moves;
	ft_printf("prev_waitlist = %d\n", prev->waitlist);
	i = 0;
	while (prev->waitlist - i++ > 0)
		if (tmp_moves)
			tmp_moves = tmp_moves->next;
	while (curr && tmp_moves)
	{
		if (tmp_moves->room_presence[curr->index] == 1)
		{
			++prev->waitlist;
			ft_printf("Oops...\n");
			return (-1);
		}
		if (curr->waitlist == 0)
		{
			curr = curr->next;
			prev = prev->next;
		}
		else
			--curr->waitlist;
		tmp_moves = tmp_moves->next;
	}
	return (1);
}

t_list	*prepare_new_path(t_map *map, t_list *path)
{
	print_moves(map);
	while (check_with_graph(&path, map) == -1)
		;
	return (path);
}
