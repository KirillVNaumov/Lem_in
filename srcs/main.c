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
	t_path	path;	

	ft_bzero(&map, sizeof(t_map));
	reading_input(&map);
	map.start_index = find_index(&map, map.start);
	map.end_index = find_index(&map, map.end);
	creating_graph(&map);
	find_all_connections_between_start_and_end(&map, &path);
	create_ant_farm(&map);
}
