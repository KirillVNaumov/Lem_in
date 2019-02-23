/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:24:20 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:24:46 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_index(t_map *map, char *name)
{
	t_rooms	*tmp;
	char	*tmp1;

	tmp1 = name;
	tmp = map->rooms;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}
