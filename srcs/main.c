/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:50:23 by amelikia          #+#    #+#             */
/*   Updated: 2019/03/04 16:56:57 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(char *reason)
{
	ft_printf("%sError: %s\n", CRED, reason);
	exit(0);
}

void	analyze_flags(char **argv, t_map *map, t_path *path)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] && argv[i][0] != '-')
			error("All the flag should start with '-'");
		++i;
	}
	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "--graph"))
			print_graph_from_map(map);
		else if (!ft_strcmp(argv[i], "--path"))
			print_path(path);
		else if (!ft_strcmp(argv[i], "--ants"))
			print_ant_farm(map);
		else if (!ft_strcmp(argv[i], "--connections"))
			print_connections(map);
		else if (!ft_strcmp(argv[i], "--moves"))
			print_moves(map);
		++i;
	}
}

int		main(int argc, char **argv)
{
	t_map	map;
	t_path	*path;

	path = NULL;
	argc = 0;
	if (argv[1] && !ft_strcmp(argv[1], "--help"))
	{
		print_usage();
		return (0);
	}
	ft_bzero(&map, sizeof(t_map));
	reading_input(&map, 0, 0);
	ft_printf("\n");
	map.start_index = find_index(&map, map.start);
	map.end_index = find_index(&map, map.end);
	creating_graph(&map);
	find_all_connections_between_start_and_end(&map, &path);
	create_ant_farm(&map);
	find_solution(&map, &path, argv);
	// free_all_data(&map, path);
}
