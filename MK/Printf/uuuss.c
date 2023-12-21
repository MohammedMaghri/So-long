/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uuu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:15:26 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/15 15:24:28 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uuusi(unsigned int number, int *len)
{
	if (number < 10)
	{
		paste(number + '0', len);
	}
	if (number > 9)
	{
		uuusi(number / 10, len);
		uuusi(number % 10, len);
	}
}
