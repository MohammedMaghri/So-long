/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:40:31 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/21 17:53:17 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	visualedit(int number)
{
	ft_printf("\n");
	ft_printf("   \033[0;93m");
	ft_printf(" By : [ Mohammed Maghri ]\n\n");
	ft_printf("\033[0;91m\n");
	ft_printf("       / #####       /  #####   / @@@         ");
	ft_printf("        /  ####################    ####    ####\n");
	ft_printf("      |  ######     /  ######                  ");
	ft_printf("       |  ####################    ####   ####\n");
	ft_printf("      |  ###  ##   /  ##  ###   | ###           ");
	ft_printf("                 ###             #### ####\n");
	ft_printf("      |  ###   ## /  ## | ###   | ###    *---------");
	ft_printf("-*         |  ###             ####  ####\n");
	ft_printf("      |  ###    ##  ##  | ###   | ###    |__________|");
	ft_printf("         |  ###             ####   ####\n");
	ft_printf("      |  ###      ##    | ###   | ###       ");
	ft_printf("                  |  ###             ####     ####\n");
	ft_printf("\033[1;97m      /  ###            / ###   | ### ");
	ft_printf("                        |  ###             ####      ####\n");
	ft_printf("\n");
	ft_printf("\033[0;93m\n");
	ft_printf("                                         ");
	ft_printf("{ %d }\n\n", number);
}

void	topaste(int signal, siginfo_t *si, void *context)
{
	int						pid;
	static unsigned char	c;
	static int				n;

	(void)context;
	pid = si->si_pid;
	if (signal == SIGUSR1 && n != 8)
		c = c | (1 << n++);
	else if (signal == SIGUSR2 && n != 8)
		c |= (0 << n++);
	if (n == 8)
	{
		if (c == '\0')
			kill(pid, SIGUSR1);
		ft_printf("%c", c);
		c = 0;
		n = 0;
	}
}

int	main(void)
{
	int					id;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = topaste;
	id = getpid();
	visualedit(id);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
