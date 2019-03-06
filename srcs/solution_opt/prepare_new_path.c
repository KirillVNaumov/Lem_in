/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_new_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:36:53 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/06 14:11:18 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		change_waitlist(t_list **prev, t_list **curr,\
	t_moves **tmp_moves, int *i)
{
	if ((*tmp_moves)->room_presence[(*curr)->index] == 1)
	{
		++(*prev)->waitlist;
		return (-1);
	}
	if ((*curr)->waitlist - (*i) == 0)
	{
		*curr = (*curr)->next;
		*prev = (*prev)->next;
		(*i) = 0;
	}
	else
		++(*i);
	return (1);
}

int		check_with_graph(t_list **path, t_map *map)
{
	t_list		*prev;
	t_list		*curr;
	t_moves		*tmp_moves;
	int			i;

	prev = *path;
	curr = (*path)->next;
	tmp_moves = map->moves;
	i = 0;
	while (prev->waitlist - i++ > 0)
		if (tmp_moves)
			tmp_moves = tmp_moves->next;
	i = 0;
	while (curr && tmp_moves)
	{
		if (change_waitlist(&prev, &curr, &tmp_moves, &i) == -1)
			return (-1);
		tmp_moves = tmp_moves->next;
	}
	return (1);
}

t_list	*prepare_new_path(t_map *map, t_list *path)
{
	while (check_with_graph(&path, map) == -1)
		;
	return (path);
}
