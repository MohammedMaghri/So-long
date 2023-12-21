/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:16:05 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/17 11:39:04 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstring(char *string, int *len)
{
	int	index;

	index = 0;
	if (!string)
	{
		write(1, "(null)", 6);
		*(len) += 6;
		return ;
	}
	while (*string)
	{
		paste(*string++, len);
	}
}
