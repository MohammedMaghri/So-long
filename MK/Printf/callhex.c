/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:39:30 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/17 10:35:52 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hex(unsigned long long nbr, int *len)
{
	unsigned long long	base_len;
	char				*base;

	base_len = 16;
	base = "0123456789abcdef";
	if (nbr < base_len)
		paste(base[nbr % base_len], len);
	else
	{
		hex(nbr / base_len, len);
		hex(nbr % base_len, len);
	}
}

void	callhex(unsigned long long number, int *len)
{
	putstring("0x", len);
	hex(number, len);
}
