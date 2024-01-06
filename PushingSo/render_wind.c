/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:57:28 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/06 16:50:24 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

void	openthis(t_fac *me)
{
	static int	movment;

	movment++ ;
	mlx_clear_window(me->forinit, me->forwindow);
	me->changedata = change_data_type(me->countmovment);
	mlx_string_put(me->forinit, me->forwindow, \
	60, 60, 0xFFD700, me->changedata);
	free(me->changedata);
	fill_window_map(me, me->twodefor);
}

int	check(char string)
{
	if (string != '1' && string != 'E')
		return (-1);
	return (0);
}

int	destro(char string, t_fac *this)
{
	static int	flag ;

	if (string == 'C')
	{
		flag += 1;
	}
	if (string == 'X')
	{
		mlx_clear_window(this->forinit, this->forwindow);
		mlx_destroy_window(this->forinit, this->forwindow);
		free(this->twodefor);
		outofgame();
	}
	return (flag);
}

int	count_collectibles(char **string)
{
	int	index ;
	int	total ;
	int	flag ;

	flag = 0;
	index = 0 ;
	total = 0;
	while (index < maplenghtcheck(string))
	{
		while (string[index][total])
		{
			if (string[index][total] == 'C')
				flag++ ;
			total++ ;
		}
		total = 0;
		index++ ;
	}
	return (flag);
}
