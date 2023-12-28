/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:52:49 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/28 18:30:24 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"
#include "mlx.h"

void	finif(t_fac *string, char **str)
{
	string->forinit = mlx_init();
	string->y = maplenghtcheck(str) + 1 ;
	string->x = lencount(str[0]);
	string->forwindow = mlx_new_window(string->forinit, \
	string->x * 60, string->y * 60 , "window");
}

char	**copymap(char *string)
{
	char	**allocation;
	char	*ptr;
	int		size ;
	int		file ;

	size = 1000 ;
	ptr = malloc(sizeof(char) * size + 1);
	file = open(string, O_RDONLY);
	thisfunctionresader(ptr, file, size);
	allocation = stringreturn(ptr);
	return (allocation);
}
void loopon(t_fac *func, char **string)
{
	func->xx = 60;
	func->yy = 60 ;
	func->pic = mlx_xpm_file_to_image(func->forinit, "Any.xpm", &func->xx, &func->yy);
	func->picB = mlx_xpm_file_to_image(func->forinit, "lay.xpm", &func->xx, &func->yy);
	func->index = 0;
	func->increment = 0;
	while (func->index <= maplenghtcheck(string))
	{
		while (string[func->index][func->increment])
		{
			func->xx = func->increment * 60;
			func->yy = func->index * 60;
			if (string[func->index][func->increment] == '1')
				mlx_put_image_to_window(func->forinit, func->forwindow, func->pic, func->xx, func->yy);
			func->increment++ ;
		}
		func->increment = 0;
		func->index++ ;
	}
}
int	main(void)
{
	t_map	mymap;
	t_fac	me;
	char	**res ;
	t_move	meme;

	mymap.checker = 60;
	mymap.numberofclomums = 60;
	res = functionoepn("map.txt", &meme);
	finif(&me, res);
	loopon(&me, res);
	mlx_loop(me.forinit);
}

	// me.pic = mlx_xpm_file_to_image(me.forinit, "Any.xpm", &mymap.checker, &mymap.numberofclomums);
	// me.picB = mlx_xpm_file_to_image(me.forinit, "lay.xpm", &mymap.checker, &mymap.numberofclomums);
	// mymap.i = 0;
	// while (mymap.i <= maplenghtcheck(res))
	// {
	// 	while (meme.doubled[mymap.i][mymap.index])
	// 	{
	// 		mymap.xx = mymap.index * 60 ;
	// 		mymap.yy = mymap.i * 60 ;
	// 		if (meme.doubled[mymap.i][mymap.index] == '1')
	// 			mlx_put_image_to_window(me.forinit, me.forwindow, me.pic, mymap.xx, mymap.yy);
	// 		else if (meme.doubled[mymap.i][mymap.index] == 'P')
	// 			mlx_put_image_to_window(me.forinit, me.forwindow, me.picB, mymap.xx, mymap.yy);
	// 		mymap.index++ ;
	// 	}
	// 	mymap.index = 0;
	// 	mymap.i++ ;