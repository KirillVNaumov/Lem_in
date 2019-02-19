# include "lem_in.h"

char        *add_char(char *str, char c)
{
    char    *tmp;

    tmp = (char *)malloc(sizeof(char) * 2);
    tmp[0] = c;
    tmp[1] = '\0';
    str = ft_update(str, ft_strjoin(str, tmp));
    free(tmp);
    return (str);
}