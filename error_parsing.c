#include "cube.h"

//Needs to add color and game exit

int error_path(int ref)
{
	ref += 3;
	printerror(ref);
	return (0);
}

/*
1 = More than one W,S,E,N characters at once !
2 = Map is not enclosed by walls
3 = Can't open the North asset file
4 = Can't open the South asset file
5 = Can't open the East asset file
6 = Can't open the West asset file
7 = Error with args, undefined chars
8 = Error RGB range
9 = invalid Rgb args
10 = Invalid map format
11 = Memory alloc failed
12 = File may not exist
*/

const char* ErrorMsg[] =
{
    "",
    "More than one W,S,E,N characters at once !",
    "Map is not enclosed by walls",
    "Can't open the North asset file",
    "Can't open the South asset file",
    "Can't open the East asset file",
    "Can't open the West asset file",
    "Error with arguments, undefined characters founds",
    "Error with RGB range, [0 ... 255]",
    "Error with RGB arguments",
    "Invalid Map Format",
    "Memory alloc failed",
    "File may not exist"
};

int printerror(ErrorCode err)
{
    ErrorCode code = err;
    if (code > 0 && code < sizeof(ErrorMsg)/sizeof(ErrorMsg[0])) 
        printf("\e[1;31mError: \033[0m\e[1;36m%s\033[0m\n", ErrorMsg[code]);
    else
        printf("Unknown error code.\n");
    return (0);
}