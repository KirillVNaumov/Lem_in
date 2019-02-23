/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_name_from_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:23:49 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:24:07 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*return_name_from_index(t_map *map, int index)
{
	t_rooms *tmp;

	tmp = map->rooms;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp->name);
		tmp = tmp->next;
	}
	return ("NULL");
}
