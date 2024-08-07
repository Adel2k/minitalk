/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:16:25 by adel              #+#    #+#             */
/*   Updated: 2024/07/23 18:34:22 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Recieved the byte.\n", 20);
}

void	char_to_bin(int pid, char *str)
{
	int		i;
	int		bit;

	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (str[i] >> bit & 1)
				kill(pid, SIGUSR1);
			else if ((str[i] >> bit & 1) == 0)
				kill(pid, SIGUSR2);
			else
			{
				write(1, "Error!", 7);
				exit (1);
			}
			usleep(1500);
			bit++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, &handler);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		char_to_bin(pid, av[2]);
		char_to_bin(pid, "\n");
	}
	else
		write(1, "Too few arguments.\n", 20);
}
