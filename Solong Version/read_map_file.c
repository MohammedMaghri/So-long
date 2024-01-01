/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:26:54 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/01 18:43:52 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

//remake this function
char	*thisfunctionresader(char *string, int fd, int size)
{
	int	readsize;

	readsize = 1;
	while (fd >= 0 && size > 0)
	{
		readsize = read(fd, string, size);
		if (readsize <= 0)
		{
			free(string);
			return (0);
		}
		string[readsize] = '\0';
	}
	if (string)
	{
		if (string[0] == '\0')
		{
			free(string);
			return (0);
		}
	}
	return (string);
}

char	**copy_of_array(char **string)
{
	int		index ;
	int		total;
	char	**alocation;

	index = 0;
	total = maplenghtcheck(string) + 1;
	alocation = malloc(sizeof(char *) * (total));
	while (index < maplenghtcheck(string))
	{
		alocation[index] = copy_of_string(string[index]);
		printf("|%s| \n \n" , alocation[index]);
		index++ ;
	}
	alocation[index] = NULL;
	printmapposition(alocation);
	return (alocation);
}

int	merge_for_moving_player(int key, t_fac *me)
{
	int	colum ;
	int	row ;

	get_monster_position(me, me->twodefor);
	row = player_row_position(me->twodefor);
	colum = player_colum_position(me->twodefor);
	move_player(key, me, row, colum);
	return (0);
}

char	**return_array_from_text(int fd)
{
	int		size;
	char	*thistext;
	char	**stringarray;

	size = 500000;
	if (fd < 0)
		return (0);
	thistext = malloc(sizeof(char) * (size + 1));
	thisfunctionresader(thistext, fd, size);
	stringarray = stringreturn(thistext);
	return (stringarray);
}

char	**get_array(char *string)
{
	t_map	putmap;

	putmap.filed = open(string, O_RDONLY);
	putmap.twode = return_array_from_text(putmap.filed);
	return (putmap.twode);
}
