/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:45:47 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/23 16:59:11 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

int	maplenghtcheck(char **string)
{
	t_map	maplenght;

	maplenght.index = 0;
	while (string[maplenght.index])
	{
		maplenght.index++ ;
	}
	return (maplenght.index - 1);
}

int	checkvalidity(int player, int collec, int out)
{
	if (player != 1)
		return (printf("The map is Not Valid Player's must  be one\n"), -1);
	if (collec < 1)
		return (printf("The map is Not Valid Collectibles are less then one\n"), -1);
	if (out != 1)
		return (printf("The map is Not Valid It must be one Exit !\n"), -1);
	return (0);
}

int	chekingarraybyone(char *string)
{
	t_map	arayby;

	arayby.index = lencount(string) - 1;
	if (string[0] != '1')
		return (printf("The map is Not Valid Sides Should have Walls....!\n"), -1);
	if (string[arayby.index] != '1')
		return (printf("The map is Not Valid Last Sides should Have Walls....!\n"), -1);
	return (0);
}

int	checksidesofmap(char **string)
{
	t_map	checksides ;

	checksides.totallenghtline = maplenghtcheck(string);
	checksides.index = 0;
	checksides.res = 0;
	while (string[checksides.index] && checksides.index < \
		checksides.totallenghtline)
	{
		checksides.res = chekingarraybyone(string[checksides.index]);
		if (checksides.res == -1)
			return (-1);
		checksides.index++ ;
	}
	return (0);
}

int	checkthelenghtline(char **array)
{
	t_map	thismap ;

	thismap.checkinglinevalidity = 0;
	thismap.index = 0;
	thismap.checkinglinevalidity = lencount(array[0]);
	while (array[thismap.index] && thismap.index < maplenghtcheck(array))
	{
		if (lencount(array[thismap.index]) != thismap.checkinglinevalidity)
			return (printf("Lines are not the same . !\n"), -1);
		thismap.index++ ;
	}
	return (0);
}

int	checktheitems(char **string)
{
	t_map	items ;

	items.index = 0;
	items.i = 0;
	items.collectiles = 0;
	items.player = 0;
	items.runout = 0;
	items.linelenght = maplenghtcheck(string);
	while (items.index < items.linelenght)
	{
		while (string[items.index][items.i])
		{
			if (string[items.index][items.i] == 'P')
				items.player += 1;
			if (string[items.index][items.i] == 'C')
				items.collectiles += 1;
			if (string[items.index][items.i] == 'E')
				items.runout += 1;
			items.i++ ;
		}
		items.i = 0;
		items.index++ ;
	}
	checkvalidity(items.player, items.collectiles, items.runout);
	return (0);
}

int	checkwalsinmap(char **string)
{
	t_map	square;

	square.index = 0;
	square.totallenghtline = maplenghtcheck(string);
	square.res = checkthelenghtline(string);
	if (lencount(string[0]) == square.totallenghtline)
		return (printf("The Map should not be a square ...! \n"), -1);
	while (string[0][square.index])
	{
		if (string[0][square.index] != '1')
			return (printf("The first Wall should Be closed ....!\n") \
				, -1);
		square.index++ ;
	}
	square.res = checksidesofmap(string);
	square.index = 0;
	while (string[square.totallenghtline][square.index])
	{
		if (string[square.totallenghtline][square.index] != '1')
			return (printf("The Last wall should Be closed By walls... !\n") \
				, -1);
		square.index++ ;
	}
	return (0);
}

int	mergetocheck(char **string)
{
	t_map	themerge ;

	themerge.index = checkwalsinmap(string);
	themerge.checker = checktheitems(string);
	return (0);
}

int	main(void)
{
	t_map	thismain;
	int		index;
	int		res;

	index = 0;
	thismain.filed = open("txt.txt", O_RDONLY);
	thismain.allocation = functionfilereader(thismain.filed);
	thismain.twode = stringreturn(thismain.allocation);
	mergetocheck(thismain.twode);
}
