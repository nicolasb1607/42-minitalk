/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:40:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/17 14:02:54 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/client.h"

int received = 0;

void handler1()
{
	return ;
}

void handler2()
{
	ft_putstr("Message send\n");
}


void end_msg(pid_t pid)
{
	int i;

	while (i < 8)
	{
		kill(pid, SIGUSR2);
		pause();
		i++;
	}
}

void send_str(char *str, pid_t pid)
{
	int i;
	int j;
	int mask;
	int sig;

	i = 0;
	while (str[i])
	{
		mask = (1 << 7);
		j = 0;
		while (j < 8)
		{
			
			sig = str[i] & mask;
			if (sig)
				kill(pid, SIGUSR1);
			else if (sig == 0)
				kill(pid, SIGUSR2);
			pause();
			mask = (mask >> 1);
			j++;
		}
		i++;
	}
	end_msg(pid);
}

int main(int ac, char **av)
{
	pid_t pid;
	
	signal(SIGUSR1, handler1);
	signal(SIGUSR2, handler2);
	
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_str(av[2], pid);
	}
	return (0);
}