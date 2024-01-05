/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:45:47 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/04 16:14:34 by mmaghri          ###   ########.fr       */
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
	return (maplenght.index);
}

int	check_double_items(char **string)
{
	t_map	items ;

	items.index = 1;
	items.i = 0;
	items.runout = 0;
	items.collectiles = 0;
	items.player = 0;
	while (items.index < maplenghtcheck(string))
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
	if (checkvalidity(items.player, items.collectiles, items.runout) == -1)
		return (-1);
	return (0);
}

int	checkwalsinmap(char **string)
{
	t_map	square;

	square.index = 0;
	square.totallenghtline = maplenghtcheck(string) - 1;
	if (checkthelenghtline(string) == -1)
		return (-1);
	if (lencount(string[0]) == square.totallenghtline)
		return (putstr("The Map should not be a square ...! \n"), -1);
	while (string[0][square.index])
	{
		if (string[0][square.index] != '1')
			return (putstr("The first Wall should Be closed ....!\n") \
				, -1);
		square.index++ ;
	}
	square.index = 0;
	while (string[square.totallenghtline][square.index])
	{
		if (string[square.totallenghtline][square.index] != '1')
			return (putstr("The Last wall should Be closed By walls... !\n") \
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
			return (putstr("\nThe Player can't reach the tokens in Map\
			 \n         Validity is invalid ..!\n\n"), -1);
		lastcheck.index++ ;
	}
	return (0);
}

int	weirddetection(char **string)
{
	int	index ;
	int	increment;
	int	flag ;

	index = 0 ;
	increment = 0 ;
	while (index < maplenghtcheck(string))
	{
		while (string[index][increment])
		{
			flag = w_check(string[index][increment]);
			if (flag == -1)
				return (-1);
			increment++ ;
		}
		increment = 0;
		index++ ;
	}
	return (0);
}
