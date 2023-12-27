/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:52:49 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/27 19:16:21 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"
#include "mlx.h"

void	finif(t_fac *string, char **str)
{
	string->forinit = mlx_init();
	string->x = maplenghtcheck(str);
	string->y = lencount(str[0]);
	string->forwindow = mlx_new_window(string->forinit, \
	string->y * 60 , string->x * 60, "window");
	mlx_loop(string->forinit);
}

int	main()
{
	t_map	mymap;
	t_fac	me;
	mymap.twode = functionoepn("map.txt");
	finif(&me, mymap.twode);
}
