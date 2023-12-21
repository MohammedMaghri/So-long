/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lencount.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:04:51 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/14 22:21:01 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lencount(char *string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		index++;
	}
	return (index);
}
