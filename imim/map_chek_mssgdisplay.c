/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chek_mssgdisplay.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:44 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/25 13:58:53 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

//check if the number of ( the col out amd player )are valid
int	checkvalidity(int player, int collec, int out)
{
	if (player != 1)
		return (printf("The map is Not Valid Player's must  be one\n"), -1);
	if (collec < 1)
		return (printf("The map is Not Valid Collectibles are less then one\n"\
			), -1);
	if (out != 1)
		return (printf("The map is Not Valid It must be one Exit !\n"), -1);
	return (0);
}

// check the first and the last index of
// the string in the array if it has walls 
int	chekingarraybyone(char *string)
{
	t_map	arayby;

	arayby.index = lencount(string) - 1;
	if (string[0] != '1')
		return (printf("The map is Not Valid Sides Should have Walls....!\n"\
			), -1);
	if (string[arayby.index] != '1')
		return (printf("The map is Not Valid Last Sides should Have Walls...!\n"\
			), -1);
	return (0);
}

// check each row if its valid or not 
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

// check the lenght of the rows in the array if they are valid (the same)
int	checkthelenghtline(char **array)
{
	t_map	thismap ;

	thismap.checkinglinevalidity = 0;
	thismap.index = 0;
	thismap.checkinglinevalidity = lencount(array[0]);
	while (array[thismap.index] && thismap.index <= maplenghtcheck(array))
	{
		if (lencount(array[thismap.index]) != thismap.checkinglinevalidity)
			return (printf("Lines are not the same . !\n"), -1);
		thismap.index++ ;
	}
	return (0);
}

int	weirddetection(char string)
{
	if (string != 'C' && string != 'P' && string != 'E' && \
	string != '1' && string != '0')
		return (printf("Wired Ithem Detected .. in the map ."), -1);
	return (0);
}
