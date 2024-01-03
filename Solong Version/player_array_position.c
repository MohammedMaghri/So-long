/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_array_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:10:02 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/03 11:07:22 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

// Funciton to display the player colum position
int	player_colum_position(char **string)
{
	t_map	columposition;

	columposition.i = 0;
	columposition.checker = 0;
	columposition.numberofclomums = maplenghtcheck(string) - 1;
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

void	get_monster_position(t_fac *this, char **string)
{
	int	index ;
	int	flag ;
	int	total ;

	index = 0 ;
	flag = 0;
	total = 0;
	while (total < maplenghtcheck(string))
	{
		while (string[total][flag])
		{
			if (string[total][flag] == 'X')
			{
				this->monster_colum = flag ;
				this->monster_row = total ;
				return ;
			}
			flag++ ;
		}
		flag = 0;
		total++ ;
	}
}

int	closeprogram(int key)
{
	(void)key ;
	exit(0);
	return (0);
}

char	**merge_functions_checks(char *string, t_fac *me)
{
	t_map	mymap;

	mymap.twode = get_array(string);
	if (maplenghtcheck(mymap.twode) > 24 || (lencount(mymap.twode[0]) > 43))
		return (printf("Mac Display can't handle this map ... !"), NULL);
	me->col = count_collectibles(mymap.twode);
	me->twodefor = copy_of_array(mymap.twode);
	mymap.xx = player_row_position(mymap.twode);
	mymap.yy = player_colum_position(mymap.twode);
	mymap.i = weirddetection(mymap.twode);
	if (mymap.i == -1)
		return (NULL);
	mymap.checker = mergecheking(mymap.twode, mymap.xx, mymap.yy);
	if (mymap.checker == -1)
		return (NULL);
	fill_struct(me, mymap.twode);
	fill_window_map(me, me->twodefor);
	mlx_hook(me->forwindow, 17, 0, closeprogram, me);
	mlx_hook(me->forwindow, 2, 0, merge_for_moving_player, me);
	mlx_loop(me->forinit);
	return (me->twodefor);
}
