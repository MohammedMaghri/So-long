/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_chek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:57:15 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/31 02:53:05 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

//check the raw that is in the colum if it actully 
//accessible with the player
int	checkrows(char *string)
{
	int	index ;

	index = 0;
	while (string[index])
	{
		if (string[index] == 'C')
			return (-1);
		if (string[index] == 'E')
			return (-1);
		index++ ;
	}
	return (0);
}

//the function that checks all the rules of the map toghter
int	mergecheking(char **string, int numbercolum, int filed)
{
	t_map	merge;

	merge.res = checkwalsinmap(string);
	if (merge.res == -1)
		return (-1);
	merge.index = checktheitems(string);
	if (merge.index == -1)
		return (-1);
	backtrack(string, numbercolum, filed);
	merge.flag = maplastcheck(string);
	if (merge.flag == -1)
		return (-1);
	return (0);
}

//this function just show live visaliwe of the map
void	printmapposition(char **string)
{
	t_map	printmappostion ;

	printmappostion.index = 0;
	printmappostion.linelenght = maplenghtcheck(string);
	while (printmappostion.index <= printmappostion.linelenght)
	{
		printf("%s\n", string[printmappostion.index]);
		printmappostion.index++ ;
	}
	printf("\n");
}

//this is the function that check is all the move are valid 
//For the player
void	backtrack(char **string, int x, int y)
{
	t_map		backtrace;

	string[x][y] = 'F';
	backtrace.linelenght = maplenghtcheck(string);
	if ((y - 1) >= 0 && string[x][y - 1] \
	!= '1' && string[x][y - 1] != 'F')
		backtrack(string, x, y - 1);
	if (x < backtrace.linelenght && string[x + 1][y] != '1' && \
	string[x + 1][y] != 'F')
		backtrack(string, x + 1, y);
	if ((y + 1) < lencount(string[x]) && \
	string[x][y + 1] != '1' && string[x][y + 1] != 'F')
		backtrack(string, x, y + 1);
	if ((x - 1) >= 0 && string[x - 1][y] != '1' \
	&& string[x - 1][y] != 'F')
		backtrack(string, x - 1, y);
}
