/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:28:59 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/04 16:04:22 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

void	putstr(char *string)
{
	while (*string)
		write(2, string++, 1);
}

int	count_number_len(int number)
{
	int	flag ;

	flag = 0;
	if (number < 0)
		flag++ ;
	while (number != 0)
	{
		number /= 10;
		flag++ ;
	}
	return (flag);
}

void	fill(int number, int lenght, int index, char *string)
{
	while (lenght >= index)
	{
		string[lenght] = (number % 10) + 48;
		number /= 10;
		lenght-- ;
	}
}

char	*change_data_type(int number)
{
	int		index ;
	int		total ;
	char	*allocation;

	index = 0 ;
	total = count_number_len(number);
	allocation = malloc(sizeof(char) * total + 1);
	if (!allocation)
		return (NULL);
	allocation[total] = '\0';
	total-- ;
	if (number < 0)
	{
		allocation[index] = '-';
		number *= -1;
		index++ ;
	}
	fill(number, total, index, allocation);
	return (allocation);
}
