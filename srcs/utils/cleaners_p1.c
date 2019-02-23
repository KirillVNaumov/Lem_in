/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners_p1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:08:58 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:10:20 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clean_list(t_list *list)
{
	if (list->next)
		clean_list(list->next);
	free(list);
}

void	clean_path(t_path *path)
{
	if (path->next)
		clean_path(path->next);
	clean_list(path->path);
	free(path);
}

void	clean_ants(t_ant **ants)
{
	int	i;

	i = 0;
	while (ants[i])
	{
		if (ants[i]->path)
			clean_list(ants[i]->path);
		free(ants[i]);
		i++;
	}
	free(ants);
}

void	clean_graph(int ***graph, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free((*graph)[i]);
		i++;
	}
	free(*graph);
}
