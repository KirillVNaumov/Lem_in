#include "lem_in.h"

int		check_for_integer(char *str)
{
	if (str[0] == '-')
		if (ft_strlen(str) > 11)
			return (-1);
	if (str[0] != '-')
		if (ft_strlen(str) > 10)
			return (-1);
	if (str[0] == '-' && ft_strlen(str) == 11)
		if (ft_strcmp(str, "-2147483648") > 0)
			return (-1);
	if (str[0] != '-' && ft_strlen(str) == 10)
		if (ft_strcmp(str, "2147483647") > 0)
			return (-1);
	return (0);
}

int		check_for_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}