/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:02:59 by aeminian          #+#    #+#             */
/*   Updated: 2024/03/22 16:03:25 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ntg)
{
    (void)ntg;
    (void)info;
	static int	bit = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
    else if (sig == SIGUSR2)
      i |= 0;
    bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		i = 0;
		bit = 0; 
	}
}
int main(int ac, char **av)
{
	(void)av;
	int pid;
	struct sigaction sa;

	pid = getpid();
	if(ac == 1)
	{
		if (pid <= 0)
		{
			ft_printf("Failure!!!!");
			exit(1);
		}
		ft_printf(">>>>>>>>>>CONNECTED TO 42POTATO'S SERVER:D<<<<<<<<<<<\nProcess ID : %d\n""Type...\n", pid);
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	return (0);
}
