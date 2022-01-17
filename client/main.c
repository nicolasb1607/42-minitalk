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

int received;

void handler1()
{
	received = 1;
	return ;
}

void handler2()
{
	ft_putstr("Message send\n");
}


void end_msg(pid_t pid)
{
	int i;
	
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		while(received == 0)
			;
		received = 0;
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
			while(received == 0)
				;
			received = 0;
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
	
	received = 0;

	signal(SIGUSR1, handler1);
	signal(SIGUSR2, handler2);
	
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_str(av[2], pid);
	}
	return (0);
}