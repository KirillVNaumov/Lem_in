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

typedef struct      s_links
{
    char            *name;
    struct s_links  *links;
}                   t_links;

typedef struct      s_rooms
{
    char            *name;
    int             x;
    int             y;
    struct s_links  *links;
}                   t_rooms;

typedef struct      s_map
{
    char            *start;
    char            *end;
    int             number_of_ants;
    struct s_rooms  *rooms;
}                   t_map;

void                error(char *reason);
void                reading_input(t_map *map);
int		            check_for_number(char *str);
int		            check_for_integer(char *str);

#endif
