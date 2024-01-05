/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_chek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:57:15 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/04 23:08:50 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

int	checkrows(char *string)
{
	int	index ;

	index = 0;
	while (string[index])
	{
		if (string[index] == 'C')
			return (-1);
		index++ ;
	}
	return (0);
}

int	movecoin(t_fac *me)
{
	static int	flag ;

	(void)me ;
	if (me->worck == 0)
		return (0);
	me->picc = ft_mlx_xpm_file_to_image(me, \
		"sym/col.xpm", me->xx, me->yy);
	openthis(me);
	me->picc = ft_mlx_xpm_file_to_image(me, \
		"sym/col.xpm", me->xx, me->yy);
	openthis(me);
	flag++ ;
	if (flag == 15)
	{
		me->picc = ft_mlx_xpm_file_to_image(me, \
			"sym/lol.xpm", me->xx, me->yy);
		openthis(me);
		me->picc = ft_mlx_xpm_file_to_image(me, \
			"sym/lol.xpm", me->xx, me->yy);
		openthis(me);
		flag = 0;
	}
	return (0);
}

int	mergecheking(char **string, int numbercolum, int filed)
{
	t_map	merge;

	merge.res = checkwalsinmap(string);
	if (merge.res == -1)
		return (-1);
	merge.i = checksidesofmap(string);
	if (merge.i == -1)
		return (-1);
	merge.index = check_double_items(string);
	if (merge.index == -1)
		return (-1);
	backtrack(string, numbercolum, filed);
	merge.flag = maplastcheck(string);
	if (merge.flag == -1)
		return (-1);
	return (0);
}

void	backtrack(char **string, int x, int y)
{
	t_map		backtrace;

	string[x][y] = 'F';
	backtrace.linelenght = maplenghtcheck(string) - 1;
	if ((y - 1) >= 0 && string[x][y - 1] \
	!= '1' && string[x][y - 1] != 'F' && string[x][y - 1] != 'X' \
	&& string[x][y - 1] != 'E')
		backtrack(string, x, y - 1);
	if (x < backtrace.linelenght && string[x + 1][y] != '1' && \
	string[x + 1][y] != 'F' && string[x + 1][y] != 'X' \
	&& string[x - 1][y] != 'E')
		backtrack(string, x + 1, y);
	if ((y + 1) < lencount(string[x]) && \
	string[x][y + 1] != '1' && string[x][y + 1] != 'F' && \
	string[x][y + 1] != 'X' && string[x][y + 1] != 'E')
		backtrack(string, x, y + 1);
	if ((x - 1) >= 0 && string[x - 1][y] != '1' \
	&& string[x - 1][y] != 'F' && string[x - 1][y] != 'X' \
	&& string[x - 1][y] != 'E')
		backtrack(string, x - 1, y);
}
