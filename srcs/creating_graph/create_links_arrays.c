/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_links_arrays.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:16:16 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/06 14:16:20 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		create_links_array(t_map *map)
{
	t_rooms	*tmp_rooms;
	t_links	*tmp_links;
	int		i;

	tmp_rooms = map->rooms;
	while (tmp_rooms)
	{
		tmp_rooms->links_array = (int *)malloc(sizeof(int) * map->length);
		tmp_links = tmp_rooms->links;
		i = 0;
		while (tmp_links)
		{
			tmp_rooms->links_array[i] = tmp_links->index;
			++i;
			tmp_links = tmp_links->next;
		}
		tmp_rooms->links_array[i] = -1;
		tmp_rooms = tmp_rooms->next;
	}
}
