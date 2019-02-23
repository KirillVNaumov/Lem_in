/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:02:24 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 17:20:58 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	assign_start_and_end(t_map *map, int *start_end, char *name)
{
	if (*start_end == 1)
	{
		if (map->start)
			error("Start has already been assigned");
		map->start = ft_strdup(name);
	}
	if (*start_end == -1)
	{
		if (map->end)
			error("End has already been assigned");
		map->end = ft_strdup(name);
	}
}

void	adding_link_process(t_map *map, char *str1, char *str2)
{
	t_rooms	*rooms;

	rooms = map->rooms;
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, str1))
			rooms->links = add_link(rooms->links, str2, find_index(map, str2));
		if (!ft_strcmp(rooms->name, str2))
			rooms->links = add_link(rooms->links, str1, find_index(map, str1));
		rooms = rooms->next;
	}
}

int		check_for_hashtag(char *line, int *start_end, int phase)
{
	if (line[0] == '#')
	{
		if (line[1] == '#')
		{
			if (!ft_strcmp(&line[2], "start"))
				*start_end = 1;
			else if (!ft_strcmp(&line[2], "end"))
				*start_end = -1;
			if (phase != 1)
				error("Start/end is misplaced");
		}
		return (1);
	}
	return (0);
}

void	find_errors(t_map *map, int phase)
{
	if (!map->start)
		error("Start has not been assigned");
	if (!map->end)
		error("End has not been assigned");
	if (phase < 2)
		error("Not enough information");
}

void	reading_input(t_map *map, int phase, int start_end)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (check_for_hashtag(line, &start_end, phase) == 1)
		{
			free(line);
			continue ;
		}
		if (!map->number_of_ants)
			phase += read_number_of_ants(map, line);
		else
		{
			if (phase == 1)
				phase += read_rooms(map, line, &start_end, 0);
			if (phase == 2)
				phase += read_links(map, line, start_end);
			if (phase == 3)
				error("Wrong Input");
		}
		free(line);
	}
	find_errors(map, phase);
}
