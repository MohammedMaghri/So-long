/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2057/11/14 22:27:00 by by mmaghri        #+#    #+#             */
/*   Updated: 2023/11/17 10:36:17 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hexxa(unsigned int nbr, char Xx, int *len)
{
	unsigned int	base_len;
	char			*base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
		paste(base[nbr % base_len], len);
	else
	{
		hexxa(nbr / base_len, Xx, len);
		hexxa(nbr % base_len, Xx, len);
	}
}

void	turn(unsigned int number, char xX, int *len)
{
	if (number < 0)
	{
		paste('-', len);
		number *= -1;
	}
	hexxa(number, xX, len);
}
