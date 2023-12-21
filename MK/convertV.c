/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertV.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:48:48 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/21 16:53:01 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	lencount(char *string)
{
	int	index ;

	index = 0 ;
	while (string[index])
	{
		index++ ;
	}
	return (index);
}

char	*inaryconv(unsigned char AR)
{
	int		i;
	int		j;
	char	res;
	char	*string;
	int		arr[7];

	res = 0;
	i = 7 ;
	j = 7 ;
	string = malloc(sizeof(string) * 8);
	if (!string)
		return (NULL);
	while (i >= 0)
	{
		arr[i] = (AR >> i) & 1;
		i--;
	}
	string[8] = '\0';
	while (j >= 0)
	{
		string[j] = arr[j] + '0';
		j--;
	}
	string[8] = '\0';
	return (string);
}

void	checkthis(char string, int pid)
{
	if (string == '1')
	{
		kill(pid, SIGUSR1);
		usleep(40);
	}
	else if (string == '0')
	{
		kill(pid, SIGUSR2);
		usleep(40);
	}
}

void	minishare(char string, int pid)
{
	char	*res ;
	int		index ;

	res = inaryconv(string);
	index = 0 ;
	while (res[index])
	{
		checkthis(res[index], pid);
		index++ ;
		if (index == 8)
		{
			free(res);
			usleep(80);
		}
	}
}
