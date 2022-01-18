/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:40:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/18 15:17:37 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/client.h"

t_data	g_data;

void	handler1(int sig)
{
	(void) sig;
	g_data.received = 1;
	return ;
}

void	end_msg(pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_data.kill_ret = kill(pid, SIGUSR2);
		if (g_data.kill_ret == -1)
		{
			ft_putstr("Error couldn't find the server\n");
			return ;
		}
		while (g_data.received == 0)
			;
		g_data.received = 0;
		i++;
	}
}

void	send_bit(char *str)
{
	g_data.sig = str[g_data.char_to_send] & g_data.mask;
	if (g_data.sig)
		g_data.kill_ret = kill(g_data.pid_server, SIGUSR1);
	else if (g_data.sig == 0)
		g_data.kill_ret = kill(g_data.pid_server, SIGUSR2);
	if (g_data.kill_ret == -1)
	{
		ft_putstr("Error couldn't find the server\n");
		return ;
	}
	while (g_data.received == 0)
		;
	g_data.received = 0;
	g_data.mask = (g_data.mask >> 1);
	g_data.bit_to_send++;
}

void	send_str(char *str, pid_t pid)
{
	g_data.char_to_send = 0;
	while (str[g_data.char_to_send])
	{
		g_data.mask = (1 << 7);
		g_data.bit_to_send = 0;
		while (g_data.bit_to_send < 8)
			send_bit(str);
		g_data.char_to_send++;
	}
	end_msg(pid);
}

int	main(int ac, char **av)
{
	g_data.received = 0;
	signal(SIGUSR1, handler1);
	signal(SIGUSR2, handler2);
	if (ac == 3)
	{
		g_data.pid_server = ft_atoi(av[1]);
		send_str(av[2], g_data.pid_server);
	}
	return (0);
}
