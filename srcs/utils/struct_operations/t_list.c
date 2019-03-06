/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:26:09 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:28:23 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*add_next_list(t_list *list, int index, t_list *tail)
{
	t_list	*new;
	t_list	*begin;

	begin = list;
	new = (t_list *)malloc(sizeof(t_list));
	new->index = index;
	new->next = tail;
	list->next = new;
	return (begin);
}

t_list		*add_front_list(t_list *list, int index, int waitlist)
{
	t_list	*new;

	if (!list)
	{
		list = (t_list *)malloc(sizeof(t_list));
		list->index = index;
		list->waitlist = waitlist;
		list->next = NULL;
		return (list);
	}
	new = (t_list *)malloc(sizeof(t_list));
	new->index = index;
	new->waitlist = waitlist;
	new->next = list;
	return (new);
}

t_list		*add_back_list(t_list *list, int index, int waitlist)
{
	t_list	*new;
	t_list	*begin;

	if (!list)
	{
		list = (t_list *)malloc(sizeof(t_list));
		list->index = index;
		list->waitlist = waitlist;
		list->next = NULL;
		return (list);
	}
	begin = list;
	new = (t_list *)malloc(sizeof(t_list));
	new->index = index;
	new->waitlist = waitlist;
	new->next = NULL;
	while (list->next)
		list = list->next;
	list->next = new;
	return (begin);
}

t_list		*delete_front_list(t_list *list)
{
	t_list	*new;

	new = list;
	if (!list->next)
	{
		free(list);
		return (NULL);
	}
	new = list->next;
	free(list);
	return (new);
}

t_list		*delete_back_list(t_list *list)
{
	t_list	*new;

	new = list;
	if (!list->next)
	{
		free(list);
		return (NULL);
	}
	while (list->next->next)
		list = list->next;
	free(list->next);
	list->next = NULL;
	return (new);
}

t_list		*copy_list(t_list *list)
{
	t_list	*new;

	new = NULL;
	while (list)
	{
		new = add_back_list(new, list->index, list->waitlist);
		list = list->next;
	}
	return (new);
}

int			size_list(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		++i;
		list = list->next;
	}
	return (i);
}

t_list  *reverse_list(t_list *list)
{
  t_list *new_list;

  new_list = NULL;
  while (list)
  {
    new_list = add_front_list(new_list, list->index, list->waitlist);
    list = list->next;
  }
  return (new_list);
}