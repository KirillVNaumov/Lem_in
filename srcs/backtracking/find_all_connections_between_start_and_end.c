/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_connections_between_start_and_end.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:25:27 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/05 16:07:05 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*get_neighbors(int *ret, int *arr, int i)
{
	int	j;

	j = 0;
	while (i >= 0)
	{
		if (arr[i] == 1)
			ret[j++] = i;
		i--;
	}
	ret[j] = -1;
	return (ret);
}

int		visited_before(int *visited, int index)
{
	int	i;

	i = 0;
	while (visited[i] != -1 && visited[i] != -2)
	{
		if (visited[i] == index)
			return (1);
		++i;
	}
	return (0);
}

int		get_last_list(t_list *list)
{
	while (list && list->next)
		list = list->next;
	// ft_printf("index: %d\n", list->last->index);
	return (list->index);
}

int		ft_intlen(int *arr)
{
	int	i;

	i = 0;
	while (1)
	{
		if (arr[i] == -1 || arr[i] == -2)
			break ;
		++i;
	}
	return (i);
}

int		*create_arr(void)
{
	int	i;
	int	*arr;

	arr = (int*)malloc(sizeof(int) * 10001);
	i = 0;
	while (i < 10000)
		arr[i++] = -2;
	arr[i] = -1;
	return (arr);
}

void	print_arr(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != -1 && arr[i] != -2)
		ft_printf("%d -> ", arr[i++]);
	ft_printf("\n");
}

void	find_all_connections_between_start_and_end(t_map *map, t_path **path)
{
	int		current;
	int		i;
	int		*neighbors;
	int		*visited;
	int		*nodestack;
	int		*indexstack;
	int		len;
	// t_list	*nodestack;
	// t_list	*indexstack;

	// nodestack = NULL;
	// indexstack = NULL;
	*path = NULL;
	i = 0;
	current = map->start_index;
	neighbors = create_arr();
	visited = create_arr();
	nodestack = create_arr();
	indexstack = create_arr();
	visited[0] = current;
	while (1)
	{
		neighbors = get_neighbors(neighbors, map->graph[current], map->length);
		while (i < ft_intlen(neighbors)\
		&& visited_before(visited, neighbors[i]) == 1)
			i++;
		if (i >= ft_intlen(neighbors))
		{
			visited[ft_intlen(visited) - 1] = -2;
			len = ft_intlen(nodestack);
			if (len < 1)
				break ;
			current = nodestack[len - 1];
			nodestack[len - 1] = -2;
			len = ft_intlen(indexstack);
			i = indexstack[len - 1];
			indexstack[len - 1] = -2;
		}
		else if (neighbors[i] == map->end_index)
		{
			len = ft_intlen(nodestack);
			nodestack[len] = current;
			nodestack[len + 1] = map->end_index;
			// *path = add_path(*path, nodestack);
			print_arr(nodestack);
			nodestack[len] = -2;
			nodestack[len + 1] = -2;
			i++;
		}
		else
		{
			nodestack[ft_intlen(nodestack)] = current;
			indexstack[ft_intlen(indexstack)] = i + 1;
			visited[ft_intlen(visited)] = neighbors[i];
			current = neighbors[i];
			i = 0;
		}
	}
}
