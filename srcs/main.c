/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:19:44 by knaumov           #+#    #+#             */
/*   Updated: 2019/02/22 13:51:21 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

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
		++i;
	}
}

void	clean_links(t_links *links)
{
	if (links->next)
		clean_links(links->next);
	free(links->name);
	free(links);
}

void	clean_rooms(t_rooms *rooms)
{
	if (rooms->next)
		clean_rooms(rooms->next);
	free(rooms->name);
	clean_links(rooms->links);
	free(rooms);
}

void	clean_list(t_list *list)
{
	if (list->next)
		clean_list(list->next);
	free(list);
}

void	clean_path(t_path *path)
{
	if (path->next)
		clean_path(path->next);
	clean_list(path->path);
	free(path);
}

void	clean_ants(t_ant **ants)
{
	int	i;

	i = 0;
	while (ants[i])
	{
		if (ants[i]->path)
			clean_list(ants[i]->path);
		free(ants[i]);
		i++;
	}
	free(ants);
}

void	clean_graph(int ***graph, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free((*graph)[i]);
		i++;
	}
	free(*graph);
}

void	free_all_data(t_map *map, t_path *path)
{
	free(map->start);
	free(map->end);
	clean_graph(&map->graph, number_of_vertices(map));
	clean_rooms(map->rooms);
	clean_path(path);
	clean_ants(map->ant_farm);
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
	reading_input(&map);
	map.start_index = find_index(&map, map.start);
	map.end_index = find_index(&map, map.end);
	creating_graph(&map);
	find_all_connections_between_start_and_end(&map, &path);
	create_ant_farm(&map);
	find_solution(&map, &path, argv);
	free_all_data(&map, path);
}
