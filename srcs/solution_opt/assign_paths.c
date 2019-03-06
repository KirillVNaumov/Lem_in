/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:05:29 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/06 14:13:38 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		sum_waitlist_and_size(t_list *list)
{
	int		sum;

	sum = 0;
	while (list)
	{
		++sum;
		sum += list->waitlist;
		list = list->next;
	}
	return (sum);
}

t_list	*find_best_path(t_path *path, t_map *map)
{
	int		best_tempi;
	int		size;
	t_list	*best_path;
	t_list	*tmp;

	best_tempi = 2147483647;
	best_path = NULL;
	while (path)
	{
		tmp = prepare_new_path(map, path->path);
		size = sum_waitlist_and_size(tmp);
		if (best_tempi > size)
		{
			best_tempi = size;
			best_path = tmp;
		}
		path = path->next;
	}
	return (copy_list(best_path));
}

void	assign_paths(t_map *map, t_path *path)
{
	int	i;

	i = 0;
	map->moves = NULL;
	while (map->ant_farm[i])
	{
		map->ant_farm[i]->path = find_best_path(path, map);
		update_moves(map, i, NULL, NULL);
		++i;
	}
}
