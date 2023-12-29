/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:52:49 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/29 12:18:58 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"
#include "mlx.h"

void	finif(t_fac *string, char **str)
{
	string->xx = 60;
	string->yy = 60 ;
	string->index = 0;
	string->increment = 0;
	string->forinit = mlx_init();
	string->y = maplenghtcheck(str) + 1 ;
	string->x = lencount(str[0]);
	string->forwindow = mlx_new_window(string->forinit, \
	string->x * 60, string->y * 60, "window");
	string->pic = mlx_xpm_file_to_image(string->forinit, \
	"Any.xpm", &string->xx, &string->yy);
	string->picc = mlx_xpm_file_to_image(string->forinit, \
	"col.xpm", &string->xx, &string->yy);
	string->picb = mlx_xpm_file_to_image(string->forinit, \
	"lay.xpm", &string->xx, &string->yy);
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

void	loopon(t_fac *func, char **string)
{
	func->xx = 60;
	func->yy = 60 ;
	func->index = 0;
	func->increment = 0;
	while (func->index <= maplenghtcheck(string))
	{
		while (string[func->index][func->increment])
		{
			func->xx = func->increment * 60;
			func->yy = func->index * 60;
			if (string[func->index][func->increment] == '1')
				mlx_put_image_to_window(func->forinit, func->forwindow, \
				func->pic, func->xx, func->yy);
			if (string[func->index][func->increment] == 'P')
				mlx_put_image_to_window(func->forinit, func->forwindow, \
				func->picb, func->xx, func->yy);
			if (string[func->index][func->increment] == 'C')
				mlx_put_image_to_window(func->forinit, func->forwindow, \
				func->picc, func->xx, func->yy);
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

	mymap.checker = 60;
	mymap.numberofclomums = 60;
	res = functionoepn("map.txt");
	finif(&me, res);
	loopon(&me, res);
	mlx_loop(me.forinit);
}
