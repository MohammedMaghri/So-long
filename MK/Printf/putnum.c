/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:31:22 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/14 19:35:44 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr(long long number, int *len)
{
	if (number < 0)
	{
		paste('-', len);
		number *= -1;
	}
	if (number < 10)
	{
		paste(number + '0', len);
	}
	if (number > 9)
	{
		putnbr(number / 10, len);
		putnbr(number % 10, len);
	}
}
