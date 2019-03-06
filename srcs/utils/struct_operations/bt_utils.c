/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:18:15 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/06 15:20:12 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*get_neighbors(int *arr, int i)
{
	t_list	*ret;

	ret = NULL;
	while (i >= 0)
	{
		if (arr[i] == 1)
			ret = add_back_list(ret, i, 0);
		i--;
	}
	return (ret);
}

int		visited_before(t_list *visited, int index)
{
	while (visited)
	{
		if (visited->index == index)
			return (1);
		visited = visited->next;
	}
	return (0);
}

int		get_last_list(t_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list->index);
}

int		get_i(t_list *neighbors, int i)
{
	int	j;

	j = 0;
	while (neighbors && j < i)
	{
		j++;
		neighbors = neighbors->next;
	}
	return (neighbors->index);
}

void	bnull(t_lists *big_l)
{
	big_l->visited = NULL;
	big_l->nodestack = NULL;
	big_l->indexstack = NULL;
	big_l->neighbors = NULL;
}
