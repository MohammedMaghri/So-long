/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:52:49 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/27 22:30:07 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"
#include "mlx.h"

void	finif(t_fac *string, char **str)
{
	string->forinit = mlx_init();
	string->y = maplenghtcheck(str);
	string->x = lencount(str[0]);
	string->forwindow = mlx_new_window(string->forinit, \
	string->x * 60 , string->y * 60, "window");
}

int	main()
{
	t_map	mymap;
	t_fac	me;

	int num = 0;
	int this = 0;
	mymap.twode = functionoepn("map.txt");
	finif(&me, mymap.twode);
	me.pic = mlx_xpm_file_to_image(me.forinit, "Any.xpm", &num, &this);
	me.picB = mlx_xpm_file_to_image(me.forinit, "lay.xpm", &num, &this);
	while (mymap.i <= maplenghtcheck(mymap.twode))
	{
		while (mymap.twode[mymap.i][mymap.index])
		{
			mymap.xx = mymap.index * 60 ;
			mymap.yy = mymap.i * 60 ;
			if (mymap.twode[mymap.i][mymap.index] == '1')
				mlx_put_image_to_window(me.forinit, me.forwindow, me.pic, mymap.xx, mymap.yy);
			else if (mymap.twode[mymap.i][mymap.index] == 'P')
				mlx_put_image_to_window(me.forinit, me.forwindow, me.picB, mymap.xx, mymap.yy);
			mymap.index++ ;
		}
		mymap.index = 0;
		mymap.i++ ;
	}
	mlx_loop(me.forinit);
	printf("%s" , me.pic);
}
