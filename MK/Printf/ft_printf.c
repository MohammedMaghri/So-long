/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:06:59 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/17 10:57:36 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check(const char string, va_list args, int *num)
{
	if (string == 'c')
		paste(va_arg(args, int), num);
	else if (string == 's')
		putstring(va_arg(args, char *), num);
	else if (string == 'd' || string == 'i')
		putnbr(va_arg(args, int), num);
	else if (string == 'p')
		callhex(va_arg(args, unsigned long long), num);
	else if (string == 'u')
		uuusi(va_arg(args, unsigned int), num);
	else if (string == 'X')
		turn(va_arg(args, unsigned int), 'X', num);
	else if (string == 'x')
		turn(va_arg(args, unsigned int), 'x', num);
	else if (string != '%')
		paste(string, num);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		res;	

	if (write(1, "", 0) == -1 || !string)
		return (-1);
	res = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			if (*(string + 1) == '%')
				paste('%', &res);
			string++;
			if (*(string) == '\0')
				return (0);
			check(*string, args, &res);
			string++;
		}
		else
			paste(*string++, &res);
	}
	va_end(args);
	return (res);
}
