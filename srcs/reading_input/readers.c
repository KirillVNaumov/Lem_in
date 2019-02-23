/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:19:19 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 17:20:10 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_number_of_ants(t_map *map, char *line)
{
	if (check_for_number(line) != -1 && check_for_integer(line) != -1)
		map->number_of_ants = ft_atoi(line);
	else
		error("No input for number of ants");
	if (map->number_of_ants <= 0)
		error("Invalid number of ants");
	return (1);
}

int		read_rooms(t_map *map, char *line, int *start_end, int i)
{
	char	*name;
	int		x;
	int		y;

	if (check_if_room(line, 0) == -1)
		return (1);
	while (line[i] != ' ')
		++i;
	name = ft_strsub(line, 0, i);
	assign_start_and_end(map, start_end, name);
	++i;
	x = ft_atoi(&line[i]);
	while (line[i] != ' ')
		++i;
	++i;
	y = ft_atoi(&line[i]);
	if (check_room_existence(map, name) == 1)
		error("Redefinition of room");
	if (check_coordinates(map, x, y) == 1)
		error("Redefinition of coordinates");
	map->rooms = add_room(map->rooms, name, x, y);
	*start_end = 0;
	free(name);
	return (0);
}

int		read_links(t_map *map, char *line, int start_end)
{
	int		i;
	char	*str1;
	char	*str2;

	if (start_end != 0)
		error("Start/end is misplaced");
	i = 0;
	str1 = ft_strnew(1);
	str2 = ft_strnew(1);
	if (ft_strchr(line, '-') == NULL)
		return (1);
	while (line[i] != '-')
		str1 = add_char(str1, line[i++]);
	++i;
	while (line[i] != '\0')
		str2 = add_char(str2, line[i++]);
	if (check_room_existence(map, str1) == -1\
	|| check_room_existence(map, str2) == -1)
		error("Room doesn't exist");
	if (check_link_existence(map, str1, str2) == 1)
		error("Link already exists");
	adding_link_process(map, str1, str2);
	free(str1);
	free(str2);
	return (0);
}
