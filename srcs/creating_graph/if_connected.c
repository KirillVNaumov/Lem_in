/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_connected.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:24:15 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 17:24:33 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		if_connected(t_map *map, int index1, int index2)
{
	t_rooms	*tmp_rooms;
	t_links	*tmp_links;

	tmp_rooms = map->rooms;
	while (tmp_rooms)
	{
		if (tmp_rooms->index == index1)
			break ;
		tmp_rooms = tmp_rooms->next;
	}
	tmp_links = tmp_rooms->links;
	while (tmp_links)
	{
		if (tmp_links->index == index2)
			return (1);
		tmp_links = tmp_links->next;
	}
	return (0);
}
