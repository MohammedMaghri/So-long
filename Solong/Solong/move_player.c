/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:34:18 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/04 12:48:10 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

int	monster_move(t_fac *me)
{
	me->foresult = get_monster_position(me, me->twodefor);
	if (me->foresult == -1)
		return (-1);
	if (me->twodefor[me->monster_row - 1][me->monster_colum] != '1' && \
	me->twodefor[me->monster_row - 1][me->monster_colum] != 'E' )
	{
		me->twodefor[me->monster_row][me->monster_colum] = '0';
		me->twodefor[--me->monster_row][me->monster_colum] = 'X';
		if (me->twodefor[me->monster_row][me->monster_colum] == 'P')
			exit(0);
	}
	else if (me->twodefor[me->monster_row + 1][me->monster_colum] != '1' && \
	me->twodefor[me->monster_row + 1][me->monster_colum] != 'E' )
	{
		me->twodefor[me->monster_row][me->monster_colum] = '0';
		me->twodefor[++me->monster_row][me->monster_colum] = 'X';
		if (me->twodefor[me->monster_row][me->monster_colum] == 'P')
			exit(0);
	}
	return (0);
}

int	count(char string)
{
	static int	flag ;

	if (string == 'C')
		flag++ ;
	return (flag);
}

void	move_player(int key, t_fac *me, int row, int colum)
{
	if ((key == 13 || key == 126) && \
	me->twodefor[row - 1][colum] == 'E' && me->worck == 0)
		exit(0);
	if ((key == 1 || key == 125) && \
	me->twodefor[row + 1][colum] == 'E' && me->worck == 0)
		exit(0);
	if ((key == 0 || key == 123) && \
	me->twodefor[row][colum - 1] == 'E' && me->worck == 0)
		exit(0);
	if ((key == 2 || key == 124) && \
	me->twodefor[row][colum + 1] == 'E' && me->worck == 0)
		exit(0);
	first_complete(key, me, row, colum);
	thiskey_complete(key, me, row, colum);
	me->worck = count_collectibles(me->twodefor);
	openthis(me);
}

void	first_complete(int key, t_fac *me, int row, int colum)
{
	if ((key == 13 || key == 126) && \
		check(me->twodefor[row - 1][colum]) == -1)
	{
		monster_move(me);
		me->countmovment++ ;
		if (me->twodefor[row][colum] == 'X')
			exit(0);
		me->twodefor[row][colum] = '0';
		me->flag = destro(me->twodefor[row - 1][colum], me);
		me->twodefor[--row][colum] = 'P';
	}
	else if ((key == 1 || key == 125) && \
		check(me->twodefor[row + 1][colum]) == -1)
	{
		monster_move(me);
		me->countmovment++ ;
		if (me->twodefor[row][colum] == 'X')
			exit(0);
		me->twodefor[row][colum] = '0';
		me->flag = destro(me->twodefor[row + 1][colum], me);
		me->twodefor[++row][colum] = 'P';
	}
}

void	thiskey_complete(int key, t_fac *me, int row, int colum)
{
	if ((key == 2 || key == 124) && check(me->twodefor[row][colum + 1]) == -1)
	{
		monster_move(me);
		me->countmovment++ ;
		if (me->twodefor[row][colum] == 'X')
			exit(0);
		me->twodefor[row][colum] = '0';
		destro(me->twodefor[row][colum + 1], me);
		me->twodefor[row][++colum] = 'P';
	}
	else if ((key == 0 || key == 123) && \
		check(me->twodefor[row][colum - 1]) == -1)
	{
		monster_move(me);
		me->countmovment++ ;
		if (me->twodefor[row][colum] == 'X')
			exit(0);
		me->twodefor[row][colum] = '0';
		destro(me->twodefor[row][colum - 1], me);
		me->twodefor[row][--colum] = 'P';
	}
}
