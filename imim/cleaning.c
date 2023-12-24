/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:45:47 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/24 15:37:34 by mmaghri          ###   ########.fr       */
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
	items.collectiles = 0;
	items.player = 0;
	items.runout = 0;
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
	checkvalidity(items.player, items.collectiles, items.runout);
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

int	mergecheking(char **string)
{
	t_map	merge;

	merge.res = checkwalsinmap(string);
	if (merge.res == -1)
		return (-1);
	merge.res = checktheitems(string);
	if (merge.res == -1)
		return (-1);
	return (0);
}

int	main(void)
{
	t_map	thismain;

	thismain.filed = open("txt.txt", O_RDONLY);
	thismain.allocation = functionfilereader(thismain.filed);
	thismain.twode = stringreturn(thismain.allocation);
	thismain.flag = mergecheking(thismain.twode);
	thismain.filed = player_colum_position(thismain.twode);
	thismain.numberofclomums = player_row_position(thismain.twode);
	printf("[%d] [%d]", thismain.numberofclomums, thismain.filed);
}
