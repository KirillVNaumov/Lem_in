/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rooms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:29:17 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:32:33 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms		*add_new_room(char *name, int x, int y)
{
	t_rooms *new;

	new = (t_rooms *)malloc(sizeof(t_rooms));
	new->x = x;
	new->y = y;
	new->name = ft_strdup(name);
	new->next = NULL;
	new->links = NULL;
	return (new);
}

t_rooms		*add_room(t_rooms *rooms, char *name, int x, int y)
{
	t_rooms	*new;
	t_rooms	*begin;

	if (!rooms)
	{
		rooms = add_new_room(name, x, y);
		rooms->index = 0;
		return (rooms);
	}
	begin = rooms;
	new = add_new_room(name, x, y);
	while (rooms->next)
		rooms = rooms->next;
	rooms->next = new;
	new->index = rooms->index + 1;
	return (begin);
}
