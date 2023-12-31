/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:57:28 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/31 03:05:01 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

//here in this function we do make a copy of the 
//2d array in here so wew can use it 
char	**copymap(char *string)
{
	char	**allocation;
	char	*ptr;
	int		size ;
	int		file ;

	size = 1000 ;
	ptr = malloc(sizeof(char) * size + 1);
	file = open(string, O_RDONLY);
	thisfunctionresader(ptr, file, size);
	allocation = stringreturn(ptr);
	return (allocation);
}

void	openthis(t_fac *me)
{
	mlx_clear_window(me->forinit, me->forwindow);
	loopon(me, me->twodefor);
}

int	check(char string)
{
	if (string != '1' && string != 'X')
		return (-1);
	return (0);
}

void	thiskey(int key, t_fac *me, int row, int colum)
{
	if (key == 13 && check(me->twodefor[row - 1][colum]) == -1)
	{
		me->twodefor[row][colum] = '0';
		row--;
		me->twodefor[row][colum] = 'P';
	}
	else if (key == 1 && check(me->twodefor[row + 1][colum]) == -1)
	{
		me->twodefor[row][colum] = '0';
		row++;
		me->twodefor[row][colum] = 'P';
	}
	if (key == 2 && check(me->twodefor[row][colum + 1]) == -1)
	{
		me->twodefor[row][colum] = '0';
		colum++;
		me->twodefor[row][colum] = 'P';
	}
	else if (key == 0 && check(me->twodefor[row][colum - 1]) == -1)
	{
		me->twodefor[row][colum] = '0';
		colum--;
		me->twodefor[row][colum] = 'P';
	}
	openthis(me);
}
