/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_representation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:34:06 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/26 22:40:42 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"
#include "mlx.h"
#include <stdio.h>

int	main(void)
{
	t_map	putmap;

	putmap.xx = 0;
	putmap.yy = 0;
	putmap.filed = open("map.txt", O_RDONLY);
	putmap.allocation = functionfilereader(putmap.filed);
	putmap.twode = stringreturn(putmap.allocation);
	putmap.numberofclomums = maplenghtcheck(putmap.twode);
	putmap.colum = lencount(putmap.twode[0]);
	putmap.ptrmlx = mlx_init();
	putmap.windowptr = mlx_new_window(putmap.ptrmlx, putmap.colum * 60, putmap.numberofclomums * 60, "Window");
	putmap.imageptr = mlx_xpm_file_to_image(putmap.ptrmlx, "pix.xpm", &putmap.xx, &putmap.yy);
	putmap.ground = mlx_xpm_file_to_image(putmap.ptrmlx, "coll.xpm", &putmap.xx, &putmap.yy);
	putmap.coll = mlx_xpm_file_to_image(putmap.ptrmlx, "coll.xpm", &putmap.xx, &putmap.yy);
	putmap.checkinglinevalidity = player_colum_position(putmap.twode);
	putmap.checker = player_row_position(putmap.twode);
	putmap.flag = mergecheking(putmap.twode, putmap.checkinglinevalidity, putmap.checker);
	printf("[%d]" , putmap.flag);
	fflush(stdout);
	putmap.i = 0;
	if (putmap.flag  == 4)
		{
			return (-1);
			mlx_destroy_window(putmap.ptrmlx, putmap.windowptr);
		}
	while (putmap.index <= maplenghtcheck(putmap.twode))
	{
		mlx_put_image_to_window(putmap.ptrmlx, putmap.windowptr, putmap.imageptr, putmap.xx, putmap.yy);
		while (putmap.twode[putmap.index][putmap.i])
		{
			putmap.yy = putmap.index * 60;
			putmap.xx = putmap.i * 60;
			if (putmap.twode[putmap.index][putmap.i] == '1')
				mlx_put_image_to_window(putmap.ptrmlx, putmap.windowptr, putmap.imageptr, putmap.xx, putmap.yy);
			if (putmap.twode[putmap.index][putmap.i] == '0')
				mlx_put_image_to_window(putmap.ptrmlx, putmap.windowptr, putmap.ground, putmap.xx, putmap.yy);
			if (putmap.twode[putmap.index][putmap.i] == 'C')
				mlx_put_image_to_window(putmap.ptrmlx, putmap.windowptr, putmap.coll, putmap.xx, putmap.yy);
			putmap.i++ ;
		}
		putmap.i = 0;
		putmap.index++ ;
	}
	mlx_loop(putmap.ptrmlx);
}
// #include "mapchek.h"
// #include <mlx.h>

// int	main(void)
// {
// 	t_map	putmap;

// 	putmap.filed = open("map.txt", O_RDONLY);
// 	putmap.allocation = functionfilereader(putmap.filed);
// 	putmap.twode = stringreturn(putmap.allocation);
// 	putmap.numberofclomums = maplenghtcheck(putmap.twode);
// 	putmap.colum = lencount(putmap.twode[0]);
// 	putmap.ptrmlx = mlx_init();
// 	putmap.windowptr = mlx_new_window(putmap.ptrmlx, putmap.colum * 60, putmap.numberofclomums * 60, "Window");
// 	putmap.imageptr = mlx_xpm_file_to_image(putmap.ptrmlx, "dd.xpm", &putmap.xx, &putmap.yy);
// 	putmap.ground = mlx_xpm_file_to_image(putmap.ptrmlx, "player.xpm", &putmap.xx, &putmap.yy);
// 	putmap.coll = mlx_xpm_file_to_image(putmap.ptrmlx, "coll.xpm", &putmap.xx, &putmap.yy);
// 	putmap.i = 0;
// 	while (putmap.index <= maplenghtcheck(putmap.twode))
// 	{
// 		mlx_put_image_to_window(putmap.ptrmlx, putmap.windowptr, putmap.imageptr, putmap.xx, putmap.yy);
// 		while (putmap.twode[putmap.index][putmap.i])
// 		{
// 			putmap.yy = putmap.index * 60;
// 			putmap.xx = putmap.i * 60;
// 			if (putmap.twode[putmap.index][putmap.i] == '1')
// 				mlx_put_image_to_window(putmap.ptrmlx, putmap.windowptr, putmap.imageptr, putmap.xx, putmap.yy);
// 			if (putmap.twode[putmap.index][putmap.i] == 'P')
// 				mlx_put_image_to_window(putmap.ptrmlx, putmap.windowptr, putmap.ground, putmap.xx, putmap.yy);
// 			else if (putmap.twode[putmap.index][putmap.i] == 'C')
// 				mlx_put_image_to_window(putmap.ptrmlx, putmap.windowptr, putmap.coll, putmap.xx, putmap.yy);
// 			putmap.i++ ;
// 		}
// 		putmap.i = 0;
// 		putmap.index++ ;
// 	}
// 	mlx_loop(putmap.ptrmlx);
// }
