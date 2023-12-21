/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:49:06 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/21 17:15:20 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	atoifunction(char *string)
{
	int		index;
	int		number;
	int		negat;

	number = 0;
	negat = 1 ;
	index = 0 ;
	while (string[index] && string[index] >= 9 && string[index] <= 13)
		index++ ;
	if (string[index] == '-' || string[index] == '+')
	{
		if (string[index] == '-')
			negat *= -1 ;
		index++;
	}
	while (string[index] >= '0' && string[index] <= '9')
	{
		number = (number * 10) + (string[index] - '0');
		index++ ;
	}
	return (number * negat);
}

void	recive(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\n\033[1;32m[message recived] ");
}

int	main(int argc, char *argv[])
{
	int		pid ;
	int		i;
	int		len;
	char	*null;
	int		index;

	if (argc != 3)
	{
		ft_printf("Usage: %s <pid>\n", argv[0]);
		return (1);
	}
	signal(SIGUSR1, recive);
	i = 0 ;
	pid = atoifunction(argv[1]);
	len = lencount(argv[2]);
	while (argv[2][i] != '\0')
		minishare(argv[2][i++], pid);
	index = 0;
	null = "00000000";
	if (i == len)
	{
		while (null[index])
			checkthis(null[index++], pid);
	}
}
