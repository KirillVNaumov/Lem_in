/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_connections_between_start_and_end.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:25:27 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/04 16:57:51 by amelikia         ###   ########.fr       */
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
	ft_printf("index in visited_before = %d\n", index);
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
	t_list	*visited;
	t_list	*nodestack;
	t_list	*indexstack;
	t_list	*neighbors;

	visited = NULL;
	nodestack = NULL;
	indexstack = NULL;
	*path = NULL;
	i = 0;
	current = map->start_index;
	visited = add_back_list(visited, current, 0);
	print_graph_from_map(map);
	while (1)
	{
		neighbors = get_neighbors(map->graph[current], map->end_index);
		ft_printf("Checking neighbords of %d\n", current);
		while (i < size_list(neighbors)\
		&& visited_before(visited, neighbors[i].index) == 1)
		{
			ft_printf("index i = %d\n", i);
			ft_printf(" - neighbor: %d\n", neighbors[i].index);
			i++;
		}
		ft_printf("done!\n");
		print_list(neighbors);
		ft_printf("pl: %d\n",neighbors[0].index);
		ft_printf("pl: %d\n",neighbors[1].index);
		if (i >= size_list(neighbors))
		{
			ft_printf("I am done with this path !\n");
			ft_printf("Deleting %d\n", current);
			visited = delete_back_list(visited);
			if (size_list(nodestack) < 1)
				break ;
			current = get_last_list(nodestack);
			nodestack = delete_back_list(nodestack);
			i = get_last_list(indexstack);
			indexstack = delete_back_list(indexstack);
		}
		else if (neighbors[i].index == map->end_index)
		{
			ft_printf("Found end !\n");
			ft_printf("Just adding %d\n", current);
			nodestack = add_back_list(nodestack, current, 0);
			ft_printf("Just adding %d\n", map->end_index);
			nodestack = add_back_list(nodestack, map->end_index, 0);
			print_list(nodestack);
			*path = add_path(*path, nodestack);
			nodestack = delete_back_list(nodestack);
			nodestack = delete_back_list(nodestack);
			i++;
		}
		else
		{
			ft_printf("Just adding %d\n", current);
			nodestack = add_back_list(nodestack, current, 0);
			indexstack = add_back_list(indexstack, i + 1, 0);
			visited = add_back_list(visited, neighbors[i].index, 0);
			current = neighbors[i].index;
			i = 0;
		}
	}
}
