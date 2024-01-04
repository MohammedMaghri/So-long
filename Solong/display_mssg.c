/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mssg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:45:39 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/04 16:14:48 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

int	checkvalidity(int player, int collec, int out)
{
	if (player != 1)
		return (putstr("The map is Not Valid Player's must  be one\n"), -1);
	if (collec < 1)
		return (putstr("The map is Not Valid Collectibles are less than one\n"\
			), -1);
	if (out != 1)
		return (putstr("The map is Not Valid It must be one Exit !\n"), -1);
	return (0);
}

int	chekingarraybyone(char *string)
{
	t_map	arayby;

	arayby.index = lencount(string) - 1;
	if (string[0] != '1')
		return (putstr("The map is Not Valid Sides Should have Walls....!\n"\
			), -1);
	if (string[arayby.index] != '1')
		return (putstr("The map is Not Valid Last Sides should Have Walls...!\n"\
			), -1);
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
	while (array[thismap.index] && thismap.index <= maplenghtcheck(array))
	{
		if (lencount(array[thismap.index]) != thismap.checkinglinevalidity)
			return (putstr("Lines are not the same . !\n"), -1);
		thismap.index++ ;
	}
	return (0);
}

int	w_check(char string)
{
	if (string != 'C' && string != 'P' && string != 'E' && \
			string != '1' && string != '0' && string != 'X')
		return (putstr("Wierd Ithems detected ..>>!!" ), -1);
	return (0);
}
