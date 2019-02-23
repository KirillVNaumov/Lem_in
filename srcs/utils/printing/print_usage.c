/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:42:54 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:43:36 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_usage(void)
{
	ft_printf("Usage: ./lem_in [optinal flags]\n");
	ft_printf("Flags:\n");
	ft_printf("--help - displays help\n");
	ft_printf("--connections - displays all the connections for all rooms\n");
	ft_printf("--graph - displays graph of the map\n");
	ft_printf("--path - ");
	ft_printf("displays all available paths from start to end points\n");
	ft_printf("--ants - displays all the ants with their paths\n");
	ft_printf("---------------------------------\n\n");
}
