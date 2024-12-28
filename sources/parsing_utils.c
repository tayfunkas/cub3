#include "cub3.h"

int ft_arraylen(char **array)
{
    int len;

    len = 0;
    while (array && array[len])
        len++;
    return (len);
}