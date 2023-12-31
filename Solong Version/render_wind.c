/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:57:28 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/31 15:34:41 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

//here in this function we do make a copy of the 
//2d array in here so wew can use it 
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

void	openthis(t_fac *me)
{
	mlx_clear_window(me->forinit, me->forwindow);
	loopon(me, me->twodefor);
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
		exit(0);
	}
	return (flag);
}

int	count_col(char **string)
{
	int	index ;
	int	total ;
	int	flag ;

	flag = 0;
	index = 0 ;
	total = 0;
	while (index <= maplenghtcheck(string))
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
