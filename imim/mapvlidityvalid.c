/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapvlidityvalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:56:33 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/23 14:28:51 by mmaghri          ###   ########.fr       */
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

int	chekingarraybyone(char *string)
{
	t_map	arayby;

	arayby.index = lencount(string) - 1;
	if (string[0] != '1')
		return (printf("Sides Should have Walls....!"), -1);
	if (string[arayby.index] != '1')
		return (printf("Last Sides should Have Walls....!"), -1);
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
	while (array[thismap.index] && thismap.index < maplenghtcheck(array))
	{
		if (lencount(array[thismap.index]) != thismap.checkinglinevalidity)
			return (printf("Lines are not the same . !\n"), -1);
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
	square.res = checkthelenghtline(string);
	if (lencount(string[0]) == square.totallenghtline)
		return (printf("The Map should not be a square ...! "), -1);
	while (string[0][square.index])
	{
		if (string[0][square.index] != '1')
			return (printf("The first Wall should Be closed ....!") \
				, -1);
		square.index++ ;
	}
	square.res = checksidesofmap(string);
	square.index = 0;
	while (string[square.totallenghtline][square.index])
	{
		if (string[square.totallenghtline][square.index] != '1')
			return (printf("The Last wall should Be closed By walls... !") \
				, -1);
		square.index++ ;
	}
	return (0);
}

int	main(void)
{
	t_map	thismain;
	int index =  0;
	thismain.filed = open("txt.txt", O_RDONLY);
	thismain.allocation = functionfilereader(thismain.filed);
	thismain.twode = stringreturn(thismain.allocation);
	int res = checkifsquare(thismain.twode);
	// {
	// 	printf("%s\n" , thismain.twode[index]);
	// 	index++ ;
	// }
}
