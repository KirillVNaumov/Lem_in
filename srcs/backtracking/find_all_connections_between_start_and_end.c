/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_connections_between_start_and_end.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:25:27 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/06 13:42:28 by amelikia         ###   ########.fr       */
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

int		get_index_of_i_node(t_list *neighbors, int i)
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

void	find_all_connections_between_start_and_end(t_map *map, t_path **path)
{
	int		current;
	int		i;
	int		vertex;
	t_list	*visited;
	t_list	*nodestack;
	t_list	*indexstack;
	t_list	*neighbors;

	visited = NULL;
	nodestack = NULL;
	indexstack = NULL;
	neighbors = NULL;
	*path = NULL;
	i = 0;
	current = map->start_index;
	vertex = number_of_vertices(map);
	visited = add_back_list(visited, current, 0);
	while (1)
	{
		if (neighbors)
			clean_list(neighbors);
		neighbors = get_neighbors(map->graph[current], map->length);
		while (i < size_list(neighbors)\
		&& visited_before(visited, get_index_of_i_node(neighbors, i)) == 1)
			i++;
		if (i >= size_list(neighbors))
		{
			visited = delete_back_list(visited);
			if (size_list(nodestack) < 1)
				break ;
			current = get_last_list(nodestack);
			nodestack = delete_back_list(nodestack);
			i = get_last_list(indexstack);
			indexstack = delete_back_list(indexstack);
		}
		else if (get_index_of_i_node(neighbors, i) == map->end_index)
		{
			nodestack = add_back_list(nodestack, current, 0);
			nodestack = add_back_list(nodestack, map->end_index, 0);
			*path = add_path(*path, nodestack);
			nodestack = delete_back_list(nodestack);
			nodestack = delete_back_list(nodestack);
			if (vertex > 1000)
				break ;
			i++;
		}
		else
		{
			nodestack = add_back_list(nodestack, current, 0);
			indexstack = add_back_list(indexstack, i + 1, 0);
			visited = add_back_list(visited, get_index_of_i_node(neighbors, i), 0);
			current = get_index_of_i_node(neighbors, i);
			i = 0;
		}
	}
	if (visited)
		clean_list(visited);
	if (nodestack)
		clean_list(nodestack);
	if (indexstack)
		clean_list(indexstack);
	if (neighbors)
		clean_list(neighbors);
}
