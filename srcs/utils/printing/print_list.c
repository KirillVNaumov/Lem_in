/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:42:09 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:42:26 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_list(t_list *list)
{
	while (list)
	{
		ft_printf("[%d]", list->index);
		if (list->next)
			ft_printf("->");
		list = list->next;
	}
	ft_printf("\n\n");
}
