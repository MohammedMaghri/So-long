/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:52:49 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/29 21:33:53 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"
#include "mlx.h"

//this function is only for checking if there is a wierd ithem in the map >
int	check_w(char **string)
{
	int	index ;
	int	total ;
	int	flag ;

	flag = 0;
	index = 0;
	total = 0;
	while (index <= maplenghtcheck(string))
	{
		while (string[index][total])
		{
			flag = weirddetection(string[index][total]);
			if (flag == -1)
				return (-1);
			total++ ;
		}
		total = 0 ;
		index++ ;
	}
	return (0);
}
//this function stores some data about the lenght S. the Window Image Ptr...
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
//here in this function we do make a copy of the 2d array in here so wew can use it 
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
//we do put each image in it place with this function 
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

int keeeey(int key, t_fac *me)
{
	(void)me;
	if(key == 53)
		exit(0);
	exit(0);
}
//in this function imtrying to find the position Player in the map so i can use it later
void	extract_position(char **string, t_fac	*meme)
{

	meme->colom= 0;
	meme->row= 0;
	meme->index = 0;
	while (meme->index <= maplenghtcheck(string))
	{
		while (string[meme->index][meme->increment])
		{
			if (string[meme->index][meme->increment] == 'P')
			{
				meme->row = meme->index ;
				meme->colom = meme->increment ;
				return ;
			}
			meme->increment++ ;
		}
			meme->increment = 0;
			meme->index++;
	}
}
int	main(void)
{
	t_fac	meme;
	char **res ;
	res = evry_thing("map.txt");
	extract_position(res, &meme);
	mlx_hook(meme.forwindow, );
	printf("%d" , meme.row);
}
