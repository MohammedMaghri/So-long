/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:52:49 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/02 20:09:11 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"
#include "mlx.h"

//this function stores some data about the lenght S. the Window Image Ptr...
void	fill_struct(t_fac *string, char **str)
{
	string->xx = 60;
	string->yy = 60 ;
	string->index = 0;
	string->increment = 0;
	string->forinit = mlx_init();
	string->y = maplenghtcheck(str);
	string->x = lencount(str[0]);
	 string->forwindow = mlx_new_window(string->forinit, \
	 (string->x * 60), (string->y * 60), "window");
	string->pic = mlx_xpm_file_to_image(string->forinit, \
	"Any.xpm", &string->xx, &string->yy);
	string->picc = mlx_xpm_file_to_image(string->forinit, \
	"col.xpm", &string->xx, &string->yy);
	string->picb = mlx_xpm_file_to_image(string->forinit, \
	"lay.xpm", &string->xx, &string->yy);
	string->picx = mlx_xpm_file_to_image(string->forinit, \
	"mypi.xpm", &string->xx, &string->yy);
	string->picz = mlx_xpm_file_to_image(string->forinit, \
	"dor.xpm", &string->xx, &string->yy);
}

void	put_character(t_fac *func, char **string)
{
	if (string[func->index][func->increment] == '1')
		mlx_put_image_to_window(func->forinit, func->forwindow, \
		func->pic, func->xx, func->yy);
	if (string[func->index][func->increment] == 'X')
		mlx_put_image_to_window(func->forinit, func->forwindow, \
		func->picb, func->xx, func->yy);
	if (string[func->index][func->increment] == 'C')
		mlx_put_image_to_window(func->forinit, func->forwindow, \
		func->picc, func->xx, func->yy);
	if (string[func->index][func->increment] == 'P')
		mlx_put_image_to_window(func->forinit, func->forwindow, \
		func->picx, func->xx, func->yy);
	if (string[func->index][func->increment] == 'E')
		mlx_put_image_to_window(func->forinit, func->forwindow, \
		func->picz, func->xx, func->yy);
	if (func->worck == 0)
		func->picz = mlx_xpm_file_to_image(func->forinit, "dorop.xpm", &func->xx, &func->yy);
}

//we do put each image in it place with this function
void	fill_window_map(t_fac *func, char **string)
{
	func->xx = 60;
	func->yy = 60 ;
	func->index = 0;
	func->increment = 0;

	while (func->index < maplenghtcheck(string))
	{
		while (string[func->index][func->increment])
		{
			func->xx = func->increment * 60;
			func->yy = func->index * 60;
			put_character(func, string);
			func->increment++ ;
		}
		func->increment = 0;
		func->index++ ;
	}
}

int checkfile_name(char *string)
{
	int total = lencount(string);

	if (string[total - 1] != 'r')
		return (printf("File name is not Valid !!"), -1);
	if (string[total - 2] != 'e')
		return (printf("File name is not Valid !!"), -1);
	if (string[total - 3] != 'b')
		return (printf("File name is not Valid !!"), -1);
	if (string[total - 4] != '.')
		return (printf("File name is not Valid!!"), -1);
	return (0);
}
int	main(int ac, char **argv)
{
	t_fac	meme;
	int		res ;

	if (ac != 2)
		return (printf("\n No Valid map to Check .... !! \n\n"), 0);
	res = checkfile_name(argv[1]);
	if (res == -1)
		return (0);
	merge_functions_checks(argv[1], &meme);
}
