/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:24:40 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/01 18:20:11 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// int	i;
// int	tmp;
//
// *list = add_front_list(*list, index[0], 0);
// if (index[0] == index[1])
// {
// 	(*path) = add_path(*path, *list);
// 	return ;
// }
// i = -1;
// while (++i < index[2])
// {
// 	if (graph[index[0]][i] == 1)
// 	{
// 		graph[i][index[0]] = 0;
// 		graph[index[0]][i] = 0;
// 		tmp = index[0];
// 		index[0] = i;
// 		algorithm(index, graph, path, list);
// 		*list = delete_front_list(*list);
// 		index[0] = tmp;
// 		graph[i][index[0]] = 1;
// 		graph[index[0]][i] = 1;
// 	}
// }

void	algorithm(int *index, int **graph, t_path **path, t_list **list)
{
	ft_printf("start: %d end: %d number_of_vertices: %d\n", index[0], index[1], index[2]);
	t_path *tesa;
	tesa = *path;
	t_list *tesaa;
	tesaa = *list;
	int *v;
	int *d;
	int tmp = 0;
	int i;
	int j;
	v = (int*)malloc(sizeof(int) * index[2]);
	d = (int*)malloc(sizeof(int) * index[2]);
	i = 0;
	while (i < index[2])
	{
		v[i] = 1;
		d[i] = 10000;
		i++;
	}
	i = 0;
	while (i < index[2])
	{
		j = 0;
		while (j < index[2])
		{
			if (graph[i][j] == 1)
			{
				tmp += 1 + graph[i][j];
				if (tmp < d[i])
					d[i] = tmp;
			}
			j++;
		}
		v[i] = 0;
		i++;
	}
	int *ver;
	ver = (int*)malloc(sizeof(int) * index[2]);
	ver[0] = index[1];
	int k = 1;

	i = 0;
	while (i < index[2])
		ft_printf("|%d|", d[i++]);
	ft_printf("\n");

	while (index[1] > 0) // пока не дошли до начальной вершины
  {
    for(int i=0; i<index[2]; i++) // просматриваем все вершины
      if (graph[index[1]][i] == 1)   // если связь есть
      {
        if (2 == d[i]) // если вес совпал с рассчитанным
        {                 // значит из этой вершины и был переход
          index[1] = i;       // сохраняем предыдущую вершину
          ver[k] = i + 1; // и записываем ее в массив
          k++;
        }
      }
  }
	i = k - 1;
	while (i >= 0)
	{
		ft_printf("|%d|", ver[i]);
		i--;
	}
	ft_printf("\n");
}
