/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:24:52 by amelikia          #+#    #+#             */
/*   Updated: 2019/02/22 16:25:03 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*add_char(char *str, char c)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * 2);
	tmp[0] = c;
	tmp[1] = '\0';
	str = ft_update(str, ft_strjoin(str, tmp));
	free(tmp);
	return (str);
}
