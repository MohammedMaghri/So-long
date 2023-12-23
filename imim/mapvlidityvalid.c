/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapvlidityvalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:56:33 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/23 13:01:57 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

int	maplenghtcheck(char **string)
{
	int	index ;

	index = 0 ;
	while (string[index])
	{
		index++ ;
	}
	return (index);
}

int	checkvalidity(int player, int collec, int out)
{
	if (player != 1)
		return (printf("Player's must only be one"), -1);
	if (collec < 1)
		return (printf("Collectibles are less then one"), -1);
	if (out != 1)
		return (printf("It must be one Exit !"), -1);
	return (0);
}

int	checkthelenghtline(char **array)
{
	t_map	thismap ;

	thismap.checkinglinevalidity = 0;
	thismap.index = 0;
	thismap.checkinglinevalidity = lencount(array[0]);
	while (array[thismap.index])
	{
		if (lencount(array[thismap.index]) != thismap.checkinglinevalidity)
			return (printf("Lines are nor the same .. !"), -1);
		thismap.index++ ;
	}
	return (0);
}

int	checkmapvaliditiy(char *string)
{
	t_map	mymap;
	int		index ;
	int		check ;

	mymap.index = 0 ;
	mymap.player = 0 ;
	mymap.collectiles = 0;
	mymap.runout = 0;
	while (string[mymap.index])
	{
		if (string[mymap.index] != 'P' && string[mymap.index] != 'C' && \
		string[mymap.index] != 'E' && string[mymap.index] != '1' && \
		string[mymap.index] != '0')
			return (printf(" Wierd ithem detected ..! "), 1);
		if (string[mymap.index] == 'P')
			mymap.player += 1 ;
		if (string[mymap.index] == 'C')
			mymap.collectiles += 1;
		if (string[mymap.index] == 'E')
			mymap.runout += 1 ;
		mymap.index++ ;
	}
	check = checkvalidity(mymap.player, mymap.collectiles, mymap.runout);
	return (check);
}

int	checkifsquare(char **string)
{
	t_map	square;

	square.index = 0;
	square.totallenghtline = maplenghtcheck(string);
	while (string[0][square.index])
	{
		if (string[0][square.index] != 1)
			return (printf("Map must be surrounded By walls....!"), -1);
		square.index++ ;
	}
	return (0);
}

int	mergecheck(char **string)
{
	t_map	check;

	check.index = 0;
	check.checker = 0;
	check.checker = checkthelenghtline(string);
	return (0);
}

int	main(void)
{
	t_map	thismain;

	thismain.filed = open("txt.txt", O_RDONLY);
	thismain.allocation = functionfilereader(thismain.filed);
	thismain.twode = stringreturn(thismain.allocation);
	
}
