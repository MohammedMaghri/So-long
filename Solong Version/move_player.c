/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:34:18 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/01 17:30:15 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

void function_use(t_fac *me, char **string)
{
   	if (string[me->monster_row - 1][me->monster_colum] != '1')
	{
		me->twodefor[me->monster_row][me->monster_colum] = '0';
		me->twodefor[--me->monster_row][me->monster_colum] = 'X';
	}
	else if (string[me->monster_row + 1][me->monster_colum] != '1')
	{
		me->twodefor[me->monster_row][me->monster_colum] = '0';
		me->twodefor[++me->monster_row][me->monster_colum] = 'X';
	}
}

void	move_player(int key, t_fac *me, int row, int colum)
{
	if ((key == 13 || key == 126) && check(me->twodefor[row - 1][colum]) == -1)
	{
		me->twodefor[row][colum] = '0';
		me->flag = destro(me->twodefor[row - 1][colum], me);
		me->twodefor[--row][colum] = 'P';
	}
	else if ((key == 1 || key == 125) && \
		check(me->twodefor[row + 1][colum]) == -1)
	{
		me->twodefor[row][colum] = '0';
		me->flag = destro(me->twodefor[row + 1][colum], me);
		me->twodefor[++row][colum] = 'P';
	}
	thiskey_complete(key, me, row, colum);
	openthis(me);
}

void	thiskey_complete(int key, t_fac *me, int row, int colum)
{
	if ((key == 2 || key == 124) && check(me->twodefor[row][colum + 1]) == -1)
	{
		me->twodefor[row][colum] = '0';
		destro(me->twodefor[row][colum + 1], me);
		me->twodefor[row][++colum] = 'P';
	}
	else if ((key == 0 || key == 123) && \
		check(me->twodefor[row][colum - 1]) == -1)
	{
		me->twodefor[row][colum] = '0';
		destro(me->twodefor[row][colum - 1], me);
		me->twodefor[row][--colum] = 'P';
	}
}
