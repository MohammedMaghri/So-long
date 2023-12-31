/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:45:47 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/30 23:03:55 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

// count the lenght of the 2d array map .
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

// function that counts items so we passe it to the function
int	checktheitems(char **string)
{
	t_map	items ;

	items.index = 0;
	items.i = 0;
	items.runout = 0;
	items.collectiles = 0;
	items.player = 0;
	while (items.index++ < maplenghtcheck(string))
	{
		while (string[items.index][items.i])
		{
			weirddetection(string[items.index][items.i]);
			if (string[items.index][items.i] == 'P')
				items.player += 1;
			if (string[items.index][items.i] == 'C')
				items.collectiles += 1;
			if (string[items.index][items.i] == 'E')
				items.runout += 1;
			items.i++ ;
		}
		items.i = 0;
	}
	if (checkvalidity(items.player, items.collectiles, items.runout) == -1)
		return (-1);
	return (0);
}

//this function checks the first row if its all walls 
//and also the last one also by making
//sure the check the whole sides with the checksides function .
int	checkwalsinmap(char **string)
{
	t_map	square;

	square.index = 0;
	square.totallenghtline = maplenghtcheck(string);
	if (checkthelenghtline(string) == -1)
		return (-1);
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

int	maplastcheck(char **string)
{
	int		res;
	t_map	lastcheck ;

	lastcheck.index = 0;
	lastcheck.totallenghtline = maplenghtcheck(string);
	res = 0;
	while (lastcheck.index < maplenghtcheck(string))
	{
		res = checkrows(string[lastcheck.index]);
		if (res == -1)
			return (printf("\nThe Player can't reach the tokens in Map\
			 \n         Validity is invalid ..!\n\n"), -1);
		lastcheck.index++ ;
	}
	return (0);
}

// int	main(void)
// {
// 	t_map	thismain;

// 	thismain.filed = open("map.txt", O_RDONLY);
// 	thismain.twode = functionfilereader(thismain.filed);
// 	thismain.filed = player_colum_position(thismain.twode);
// 	thismain.numberofclomums = player_row_position(thismain.twode);
// 	mergecheking(thismain.twode, thismain.numberofclomums, thismain.filed);
// 	printmapposition(thismain.twode);
// }
