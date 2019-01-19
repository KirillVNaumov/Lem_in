/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:19:44 by knaumov           #+#    #+#             */
/*   Updated: 2019/01/03 17:57:22 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

void	error(char *reason)
{
	ft_printf("%sError: %s\n", CRED, reason);
	exit(0);
}

int		main(void)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	reading_input(&map);
	if (find_connection(&map) == -1)
		error("There is no connection between start and end points");
}
