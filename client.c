/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:16:25 by adel              #+#    #+#             */
/*   Updated: 2024/03/19 11:17:05 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int main(int ac, char **av)
{
	int	pid;

	if(ac == 3)
	{
		pid = ft_atoi(av[1]);
		char_to_bin(pid, av[2]);
	}
	else
		ft_printf("Too few arguments.\n");
}
