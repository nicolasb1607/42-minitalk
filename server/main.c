/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:37:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/17 15:27:35 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/server.h"

t_data g_data;

void print_pid()
{
	pid_t pid;

	pid = getpid();
	printf("PID : %d\n", pid);
}

void receive_char(int sig, siginfo_t *siginfo, void *context)
{
	g_data.pid_client = siginfo->si_pid;
	(void)context;

	if (sig == SIGUSR1 && g_data.bits < 8)
		g_data.char_received |= (1 << (7 - g_data.bits++));
	if (sig == SIGUSR2 && g_data.bits < 8)
		g_data.char_received &= ~(1 << (7 - g_data.bits++));
	g_data.sig_received = 1;
}

int main()
{
	struct sigaction sa;
	char *tmp;
	
	g_data.char_received = 0;
	g_data.bits = 0;
	g_data.msg = malloc(sizeof(char) * 1);
	g_data.msg[0] = '\0';

	sa.sa_sigaction = receive_char;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	print_pid();
	while (1)
	{
		if (g_data.sig_received == 1)
		{
			if (g_data.bits == 8 && g_data.char_received == 0)
			{
				ft_putstr(g_data.msg);
				ft_putchar('\n');
				free(g_data.msg);
				g_data.char_received = 0;
				g_data.bits = 0;
				kill(g_data.pid_client, SIGUSR2);
			}
			if (g_data.bits == 8)
			{
				g_data.msg = ft_strjoin(g_data.msg, g_data.char_received);
				g_data.char_received = 0;
				g_data.bits = 0;
			}
			g_data.sig_received = 0;
			kill(g_data.pid_client, SIGUSR1);
		}
	
	}
	return (0);
}