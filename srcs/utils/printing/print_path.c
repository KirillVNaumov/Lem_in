/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:42:34 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:42:49 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_path(t_path *path)
{
	t_list	*tmp;

	ft_printf("PRINT_PATH\n");
	ft_printf("---------------------------------\n");
	while (path)
	{
		tmp = path->path;
		print_list(tmp);
		path = path->next;
	}
	ft_printf("---------------------------------\n");
}
