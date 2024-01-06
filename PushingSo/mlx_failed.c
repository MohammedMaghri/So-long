/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_failed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:20:39 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/06 17:35:30 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

void	*ft_mlx_init(void)
{
	void	*res;

	res = mlx_init();
	if (!res)
		exit(1);
	return (res);
}

void	*ft_mlx_new_window(t_fac *me)
{
	void	*res;

	res = mlx_new_window(me->forinit, \
	(me->x * 60), (me->y * 60), "window");
	if (!res)
		exit (1);
	return (res);
}

void	*ft_mlx_xpm_file_to_image(t_fac *me, char *string, int x, int y)
{
	void	*res;

	res = mlx_xpm_file_to_image(me->forinit, string, &x, &y);
	if (!res)
		exit(1);
	return (res);
}

void	reethfunction(char **string)
{
	int	index ;
	int	total ;

	total = maplenghtcheck(string);
	index = 0;
	while (index < total)
	{
		free(string[index]);
		index++ ;
	}
	free(string);
}

void	outofgame(void)
{
	putstr("See You Next Time ;)");
	exit(1);
}
