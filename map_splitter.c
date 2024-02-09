/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::   	  */
/*   map_splitter.c									 :+:	  :+:	:+:       */
/*													+:+ +:+		 +:+	      */
/*   By: zfavere <marvin@42.fr>					 +#+  +:+	   +#+		      */
/*												+#+#+#+#+#+   +#+		      */
/*   Created: 2024/02/08 19:18:50 by zfavere		   #+#	#+#			      */
/*   Updated: 2024/02/08 19:18:51 by zfavere		  ###   ########.fr	      */
/*																			  */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Utility function to check if a string consists only of spaces and numbers
static int is_spaces_and_numbers_only(const char* str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str) && !isdigit((unsigned char)*str))
			return (0); // Contains more than spaces and numbers
		str++;
	}
	return (1); // Only spaces and numbers
}

void split_map(char** map, char*** part1, char*** part2)
{
	int totalLines = 0;
	while (map[totalLines])
		totalLines++; // Count total lines

	// Temporary solution to estimate sizes, exact allocation will vary
	*part1 = malloc(sizeof(char*) * (totalLines + 1));
	*part2 = malloc(sizeof(char*) * (totalLines + 1));

	if (!*part1 || !*part2)
	{
		printf("Memory allocation failed.\n");
		return;
	}

	int i = 0;
	int j = 0;
	int splittingPointFound = 0;
	while (i < totalLines)
	{
		if (!splittingPointFound && is_spaces_and_numbers_only(map[i]))
		{
			splittingPointFound = 1; // Found the split point
		}

		if (!splittingPointFound) 
		{
			(*part1)[i] = strdup(map[i]);
		}
		else 
		{
			(*part2)[j++] = strdup(map[i]);
		}
		i++;
	}
	(*part1)[i] = NULL; // Null-terminate part1 array
	(*part2)[j] = NULL; // Null-terminate part2 array
}
