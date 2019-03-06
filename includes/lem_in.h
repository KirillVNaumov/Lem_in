/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:20:46 by knaumov           #+#    #+#             */
/*   Updated: 2019/03/06 13:16:09 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# define CRED       "\x1B[31m"
# define CWHITE     "\x1B[39m"
# define CBLUE      "\x1B[34m"

typedef struct			s_moves
{
	int					*room_presence;
	struct s_moves		*next;
}						t_moves;

typedef struct			s_ant
{
	struct s_list		*path;
	int					room_index;
	int					rooms_passed;
}						t_ant;

typedef struct			s_list
{
	int					index;
	int					waitlist;
	struct s_list		*last;
	struct s_list		*next;
}						t_list;

typedef struct			s_path
{
	struct s_list		*path;
	int					length;
	struct s_path		*next;
}						t_path;

typedef struct			s_links
{
	char				*name;
	int					index;
	struct s_links		*next;
}						t_links;

typedef struct			s_rooms
{
	char				*name;
	int					index;
	int					x;
	int					y;
	int					*links_array;
	struct s_links		*links;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_map
{
	char				*start;
	char				*end;
	int					start_index;
	int					end_index;
	int					number_of_ants;
	int					length;
	int					**graph;
	t_moves				*moves;
	t_ant				**ant_farm;
	struct s_rooms		*rooms;
}						t_map;

/*
** MAIN
*/

void					error(char *reason);

/*
** READING_INPUT
*/

void					reading_input(t_map *map, int phase, int start_end);
int						read_rooms(t_map *map, char *line,\
	int *start_end, int i);
int						read_links(t_map *map, char *line, int start_end);
int						read_number_of_ants(t_map *map, char *line);
void					assign_start_and_end(t_map *map,\
	int *start_end, char *name);
void					adding_link_process(t_map *map,\
	char *str1, char *str2);
int						check_for_number(char *str);
int						check_for_integer(char *str);
int						check_if_room(char *line, int i);
int						check_link_existence(t_map *map,\
	char *room, char *link);
int						check_room_existence(t_map *map, char *room);
int						check_coordinates(t_map *map, int x, int y);
void					analyze_flags(char **argv, t_map *map, t_path *path);

/*
** STRUCT_OPERATIONS
*/

void					create_ant_farm(t_map *map);
t_links					*add_link(t_links *links, char *name, int index);
t_list					*add_front_list(t_list *list, int index, int waitlist);
t_list					*add_back_list(t_list *list, int index, int waitlist);
t_list					*delete_front_list(t_list *list);
t_list					*delete_back_list(t_list *list);
t_list					*add_next_list(t_list *list, int index, t_list *tail);
t_list					*copy_list(t_list *list);
int						size_list(t_list *list);
t_list					*reverse_list(t_list *list);
t_path					*add_path(t_path *path, t_list *list);
t_path					*sort_path(t_path *list);
t_rooms					*add_room(t_rooms *rooms, char *name, int x, int y);
t_moves					*add_moves(t_moves *graph, t_map *map);

/*
** PRINTING
*/

void					print_connections(t_map *map);
void					print_graph_from_map(t_map *map);
void					print_graph(int **graph, int size);
void					print_path(t_path *path);
void					print_list(t_list *list);
void					print_ant_farm(t_map *map);
void					print_moves(t_map *map);
void					print_usage();

/*
** UTILS
*/

char					*add_char(char *str, char c);
int						find_index(t_map *map, char *name);
char					*return_name_from_index(t_map *map, int index);

/*
** CREATING_GRAPH
*/

void					create_links_array(t_map *map);
void					creating_graph(t_map *map);
int						number_of_vertices(t_map *map);
int						*if_connected(t_map *map, int index);

/*
** BACKTRACKING
*/

void					find_all_connections_between_start_and_end(t_map *map,\
	t_path **path);

/*
** SOLUTION_OPT
*/

void					find_solution(t_map *map, t_path **path, char **argv);
void					move_ants(t_map *map);
void					assign_paths(t_map *map, t_path *path);
t_list				    *prepare_new_path(t_map *map, t_list *path);
void					update_moves(t_map *map, int i);

/*
** CLEANING
*/

void					clean_list(t_list *list);
void					clean_links(t_links *links);
void					clean_rooms(t_rooms *rooms);
void					clean_path(t_path *path);
void					clean_ants(t_ant **ants);
void					clean_graph(int ***graph, int size);
void					free_all_data(t_map *map, t_path *path);

#endif
