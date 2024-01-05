/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_failed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:20:39 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/04 23:06:20 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"
#include "mlx.h"

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
