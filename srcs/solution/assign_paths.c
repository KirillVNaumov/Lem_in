/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:55:50 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:57:57 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*find_best_path(t_path *path, t_map *map, int i, int best_tempi)
{
	t_path	*best_choice;
	t_list	*tmp;
	t_list	*final_list;

	final_list = NULL;
	best_choice = NULL;
	while (path)
	{
		tmp = match_to_others(copy_list(path->path), map, i);
		if (tmp->index != -1)
		{
			if (best_tempi > size_list(tmp))
			{
				best_tempi = size_list(tmp);
				if (final_list)
					clean_list(final_list);
				final_list = copy_list(tmp);
				best_choice = path;
			}
			clean_list(tmp);
		}
		path = path->next;
	}
	return (final_list);
}

void	assign_paths(t_map *map, t_path *path)
{
	int	i;
	int best_tempi;

	best_tempi = 2147483647;
	i = 0;
	while (map->ant_farm[i])
	{
		map->ant_farm[i]->path = find_best_path(path, map, i, best_tempi);
		++i;
	}
}
