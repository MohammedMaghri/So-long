/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:26:54 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/04 16:15:31 by mmaghri          ###   ########.fr       */
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

char	**copy_of_array(char **string)
{
	int		index ;
	int		total;
	char	**alocation;

	index = 0;
	total = maplenghtcheck(string) + 1;
	alocation = malloc(sizeof(char *) * (total));
	if (!alocation)
		return (NULL);
	while (index < maplenghtcheck(string))
	{
		alocation[index] = copy_of_string(string[index]);
		index++ ;
	}
	alocation[index] = NULL;
	return (alocation);
}

int	merge_for_moving_player(int key, t_fac *me)
{
	int	colum ;
	int	row ;

	if (key == 53 || key == 12)
		exit(0);
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
	if (!thistext)
		return (NULL);
	thisfunctionresader(thistext, fd, size);
	stringarray = stringreturn(thistext);
	return (stringarray);
}

char	**get_array(char *string)
{
	t_map	putmap;

	putmap.filed = open(string, O_RDONLY);
	if (putmap.filed == -1)
	{
		putstr("No File >>> !");
		exit(0);
	}
	putmap.twode = return_array_from_text(putmap.filed);
	return (putmap.twode);
}
