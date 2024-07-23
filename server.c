/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:02:59 by aeminian          #+#    #+#             */
/*   Updated: 2024/07/23 15:59:39 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ntg)
{
	static int	bit;
	static int	i;

	(void)ntg;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	else if (sig == SIGUSR2)
		i |= 0;
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		i = 0;
		bit = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	(void)av;
	pid = getpid();
	if (ac == 1)
	{
		if (pid <= 0)
		{
			write(1, "Failure!!!!", 12);
			exit(1);
		}
		ft_printf(">>>>>>>>>>CONNECTED TO 42POTATO'S SERVER");
		ft_printf(":D<<<<<<<<<<<\nProcess ID : %d\nType...\n", pid);
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	return (0);
}

// system("leaks minitalk");