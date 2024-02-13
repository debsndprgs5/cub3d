#include "cube.h"


char    *removes_first_spaces(char *str, int i)
{
    char    *new_str;
    int     j;
    
    j = 0;
    while(str[i])
    {
        if(str[i] != ' ' || str[i] != ' ')
            break;
        i++;
    }
    if (i >= ft_strlen(str))
        return (NULL);
    new_str = malloc(sizeof(char)* (ft_strlen(str) - i) +1);
    while (i <= ft_strlen(str))
    {
        new_str[j] = str[i];
        j++;
        i++;
    }
    if(new_str[j-1] == '\n')
    {  
        new_str[j-1] = '\0';
    }
    else
        new_str[j] = '\0';
    return (new_str);
}