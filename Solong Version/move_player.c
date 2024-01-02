/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:34:18 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/02 20:08:33 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

int monster_move(int key, t_fac *me)
{
	(void)key ;
   	if (me->twodefor[me->monster_row - 1][me->monster_colum] != '1')
		{
			me->twodefor[me->monster_row][me->monster_colum] = '0';
			me->twodefor[--me->monster_row][me->monster_colum] = 'X';
		}
	else if (me->twodefor[me->monster_row + 1][me->monster_colum] != '1')
		{
			me->twodefor[me->monster_row][me->monster_colum] = '0';
			me->twodefor[++me->monster_row][me->monster_colum] = 'X';
		}
	return 0;
}

int count(char string)
{
	static int flag ;

	if (string == 'C')
		flag++ ;
	return (flag);
}

void	move_player(int key, t_fac *me, int row, int colum)
{
	// mlx_string_put(me->forinit, me->forwindow, 60, 60, 0xFFD700, me->changedata);
	if ((key == 13 || key == 126) && me->twodefor[row - 1][colum] != '1')
	{
		me->countmovment++ ;
		monster_move(key , me);
		if (me->twodefor[row][colum] == 'X')
			exit(0);
		me->twodefor[row][colum] = '0';
		if (me->twodefor[row - 1][colum] == 'E' && me->worck == 0)
			exit(0);
		me->flag = destro(me->twodefor[row - 1][colum], me);
		me->twodefor[--row][colum] = 'P';
	}
	else if ((key == 1 || key == 125) && \
		check(me->twodefor[row + 1][colum]) == -1)
	{
		me->countmovment++ ;
		monster_move(key , me);
		if (me->twodefor[row][colum] == 'X')
			exit(0);
		me->twodefor[row][colum] = '0';
		me->flag = destro(me->twodefor[row + 1][colum], me);
		me->twodefor[++row][colum] = 'P';
	}
	thiskey_complete(key, me, row, colum);
	me->worck = count_collectibles(me->twodefor);
	openthis(me);
}

void	thiskey_complete(int key, t_fac *me, int row, int colum)
{
	if ((key == 2 || key == 124) && check(me->twodefor[row][colum + 1]) == -1)
	{
		me->countmovment++ ;
		monster_move(key , me);
		if (me->twodefor[row][colum] == 'X')
			exit(0);
		me->twodefor[row][colum] = '0';
		destro(me->twodefor[row][colum + 1], me);
		me->twodefor[row][++colum] = 'P';
	}
	else if ((key == 0 || key == 123) && \
		check(me->twodefor[row][colum - 1]) == -1)
	{
		me->countmovment++ ;
		monster_move(key , me);
		if (me->twodefor[row][colum] == 'X')
			exit(0);
		me->twodefor[row][colum] = '0';
		destro(me->twodefor[row][colum - 1], me);
		me->twodefor[row][--colum] = 'P';
	}
}
