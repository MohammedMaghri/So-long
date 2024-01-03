/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complet_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:34:18 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/31 16:42:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

void	thiskey(int key, t_fac *me, int row, int colum)
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
