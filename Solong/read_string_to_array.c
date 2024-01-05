/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_string_to_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:31:43 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/05 13:11:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

int	lencount(char *string)
{
	t_map	count;

	count.index = 0;
	while (string[count.index])
	{
		count.index++ ;
	}
	return (count.index);
}

char	*copy_of_string(char *string)
{
	t_map	make;

	make.index = 0;
	make.allocation = malloc(sizeof(char) * (lencount(string) + 1));
	if (!make.allocation)
	{
		return (NULL);
	}
	while (string[make.index])
	{
		make.allocation[make.index] = string[make.index];
		make.index++ ;
	}
	make.allocation[make.index] = '\0';
	return (make.allocation);
}

char	*new_copy_lenght(char *string, int maxlenght)
{
	t_map	copy;

	copy.index = 0 ;
	copy.allocation = malloc(sizeof(char) * maxlenght + 1);
	if (!copy.allocation)
	{
		return (NULL);
	}
	while (string[copy.index] && copy.index <= maxlenght)
	{
		copy.allocation[copy.index] = string[copy.index];
		copy.index++ ;
	}
	copy.allocation[copy.index] = '\0';
	return (copy.allocation);
}

int	countnewline(char *string)
{
	t_map	newlinecount;

	newlinecount.index = 0;
	newlinecount.flag = 0;
	while (string[newlinecount.index])
	{
		if (string[newlinecount.index] == '\n')
			newlinecount.flag++ ;
		newlinecount.index++ ;
	}
	return (newlinecount.flag + 1);
}

char	**stringreturn(char *string)
{
	t_map	turn;
	char *tmp;

	turn.index = 0;
	turn.i = 0 ;
	turn.twode = malloc(sizeof(char *) * ((countnewline(string)) + 1));
	if (!turn.twode)
		return (free(turn.twode), NULL);
	while (string[turn.index])
	{
		if (string[turn.index] == '\n')
		{
			turn.checkpoint = turn.index ;
			turn.index++ ;
			turn.checkpoint--;
			turn.twode[turn.i] = new_copy_lenght(string, turn.checkpoint);
			tmp = copy_of_string(&string[turn.index]);
			free(string);
			string = tmp;
			turn.index = 0;
			turn.i++ ;
		}
		turn.index++ ;
	}
	turn.twode[turn.i] = copy_of_string(string);
	free(string);
	turn.i++ ;
	turn.twode[turn.i] = NULL ;
	return turn.twode;
}
