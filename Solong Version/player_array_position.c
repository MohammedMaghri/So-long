/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_array_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:10:02 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/29 16:49:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

// Funciton to display the player colum position
int	player_colum_position(char **string)
{
	t_map	columposition;

	columposition.i = 0;
	columposition.checker = 0;
	columposition.numberofclomums = maplenghtcheck(string);
	while (columposition.checker < columposition.numberofclomums)
	{
		while (string[columposition.checker][columposition.i])
		{
			if (string[columposition.checker][columposition.i] == 'P')
				return (columposition.i);
			columposition.i++ ;
		}
		columposition.i = 0;
		columposition.checker++ ;
	}
	return (0);
}

//Function to extract the player row position
int	player_row_position(char **string)
{
	t_map	position ;

	position.i = 0;
	position.checker = 0;
	position.numberofclomums = maplenghtcheck(string);
	while (position.checker < position.numberofclomums)
	{
		while (string[position.checker][position.i])
		{
			if (string[position.checker][position.i] == 'P')
				return (position.checker);
			position.i++ ;
		}
		position.i = 0;
		position.checker++ ;
	}
	return (0);
}

int	evry_thing(char *string)
{
	t_map	mymap;
	t_fac	me;

	mymap.twode = functionoepn(string);
	mymap.checker = check_w(mymap.twode);
	if (mymap.checker == -1)
		return (-1);
	finif(&me, mymap.twode);
	loopon(&me, mymap.twode);
	mlx_loop(me.forinit);
	return (0);
}
