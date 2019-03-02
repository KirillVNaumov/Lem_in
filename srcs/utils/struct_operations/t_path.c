/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:28:32 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:29:11 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*add_path(t_path *path, t_list *list)
{
	t_path	*new;

	if (!path)
	{
		path = (t_path *)malloc(sizeof(t_path));
		path->path = copy_list(list);
		path->length = size_list(list);
		path->next = NULL;
		return (path);
	}
	new = (t_path *)malloc(sizeof(t_path));
	new->path = copy_list(list);
	new->length = size_list(list);
	new->next = path;
	return (new);
}

t_path		*sort_path(t_path *path)
{
	t_path	*head;
	t_list	*tmp_list;
	int		tmp_length;

	head = path;
	while (path && path->next)
	{
		if (path->length > path->next->length)
		{
			tmp_list = path->path;
			tmp_length = path->length;
			path->path = path->next->path;
			path->length = path->next->length;
			path->next->path = tmp_list;
			path->next->length = tmp_length;
			path = head;
		}
		else
			path = path->next;
	}
	path = head;
	return (path);
}
