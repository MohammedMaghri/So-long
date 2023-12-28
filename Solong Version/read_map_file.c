/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:26:54 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/28 17:07:21 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

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
char	**putfromtoother(char **string)
{
	int index = 0;
	int total = maplenghtcheck(string);
	char **alocation = malloc(sizeof(char **) * total);
	while (index <= total)
	{
		alocation[index] = makestringopy(string[index]);
		index++ ;
	}
	alocation[index] = NULL ;
	return alocation;
}
char	**functionfilereader(int fd, t_move *map)
{
	t_map	filereader;
	int		size;
	char	*thistext;
	char	**stringarray;

	size = 10000;
	if (fd < 0)
		return (0);
	thistext = malloc(sizeof(char) * size + 1);
	thisfunctionresader(thistext, fd, size);
	stringarray = stringreturn(thistext);
	map->doubled = putfromtoother(stringarray);
	filereader.numberofclomums = player_row_position(stringarray);
	filereader.colum = player_colum_position(stringarray);
	filereader.checker = mergecheking(stringarray, \
	filereader.numberofclomums, filereader.colum);
	if (filereader.checker == -1)
		return (exit(1), NULL);
	return (stringarray);
}

char	**functionoepn(char *string, t_move *map)
{
	t_map	putmap;

	putmap.filed = open(string, O_RDONLY);
	putmap.twode = functionfilereader(putmap.filed, map);
	return (putmap.twode);
}
