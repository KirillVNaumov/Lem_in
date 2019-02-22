/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:20:46 by knaumov           #+#    #+#             */
/*   Updated: 2019/01/03 17:59:30 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# define CRED       "\x1B[31m"
# define CWHITE     "\x1B[39m"
# define CBLUE      "\x1B[34m"

typedef struct      s_ant
{
    struct s_list   *path;
    int             room_index;
    int             waitlist;
    int             rooms_passed;
}                   t_ant;

typedef struct      s_list
{
    int             index;
    struct s_list   *next;
}                   t_list;

typedef struct      s_path
{
    struct s_list   *path;
    int             length;
    int             waitlist;
    struct s_path   *next;
}                   t_path;

typedef struct      s_links
{
    char            *name;
    int             index;
    struct s_links  *next;
}                   t_links;

typedef struct      s_rooms
{
    char            *name;
    int             index;
    int             x;
    int             y;
    struct s_links  *links;
    struct s_rooms  *next;
}                   t_rooms;

typedef struct      s_map
{
    char            *start;
    char            *end;
    int             start_index;
    int             end_index;
    int             number_of_ants;
    int             **graph;
    t_ant           **ant_farm;
    struct s_rooms  *rooms;
}                   t_map;

//  MAIN
void	            error(char *reason);

//  READING_INPUT
void                reading_input(t_map *map);
int		            check_for_number(char *str);
int		            check_for_integer(char *str);
int                 check_if_room(char *line);
int                 check_link_existence(t_map *map, char *room, char *link);
int                 check_room_existence(t_map *map, char *room);
int                 check_coordinates(t_map *map, int x, int y);
void	            analyze_flags(char **argv, t_map *map, t_path *path);

//  STRUCT_OPERATIONS

void                create_ant_farm(t_map *map);
t_links             *add_link(t_links *links, char *name, int index);
t_list              *add_list(t_list *list, int index);
t_list              *add_next_list(t_list *list, int index, t_list *tail);
t_list              *delete_list(t_list *list);
t_list              *copy_list(t_list *list);
int                 size_list(t_list *list);
t_path              *add_path(t_path *path, t_list *list);
t_path              *sort_path(t_path *list);
t_rooms             *add_room(t_rooms *rooms, char *name, int x, int y);

/*
** PRINTING
*/

void                print_connections(t_map *map);
void                print_graph_from_map(t_map *map);
void                print_graph(int **graph, int size);
void                print_path(t_path *path);
void                print_list(t_list *list);
void                print_ant_farm(t_map *map);
void                print_usage();

//  UTILS

char                *add_char(char *str, char c);
int                 find_index(t_map *map, char *name);
char                *return_name_from_index(t_map *map, int index);

//  CREATING_GRAPH
int                 find_connection(t_map *map);
void                creating_graph(t_map *map);
int                 number_of_vertices(t_map *map);
int                 if_connected(t_map *map, int index1, int index2);

//  BACKTRACKING
void                find_all_connections_between_start_and_end(t_map *map, t_path **path);
void                algorithm(int *index, int **graph, t_path **path, t_list *list);

//  SOLUTION
void                find_solution(t_map *map, t_path **path, char **argv);
void                move_ants(t_map *map);
void                assign_paths(t_map *map, t_path *path);
t_list              *match_to_others(t_list *path, t_map *map, int i);

#endif
