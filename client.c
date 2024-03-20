/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:16:25 by adel              #+#    #+#             */
/*   Updated: 2024/03/20 21:19:00 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

void	char_to_bin(int pid, char *str)
{
	int		i;
	int		bit;
	char	res;

	i = 0;
	bit = 7;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
		{
			res = (str[i] &(1 << bit)) ? '1' : '0';
			if (res == '1')
				kill(pid, SIGUSR1);
			else if (res == '0')
				kill(pid, SIGUSR2);
			else
			{
				ft_printf("Error!");
				exit (1);
			}
			usleep(500);
			bit++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = atoi(av[1]);
		char_to_bin(pid, av[2]);
	}
	else
		printf("Too few arguments.\n");
}
