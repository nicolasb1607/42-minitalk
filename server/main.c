/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:37:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/17 15:50:34 by nburat-d         ###   ########.fr       */
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

	

	g_data.char_received = 0;
	g_data.bits = 0;
	char *str = malloc(sizeof(char) * 1);
	str[0] = '\0';


	sa.sa_sigaction = receive_char;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	print_pid();
	
	while (1)
	{
		if (g_data.sig_received == 1)
		{
			if (g_data.bits == 8)
			{
				//printf("passage: %i str : %s\n", i, str);
				str = ft_strjoin(str, g_data.char_received);
				if (g_data.char_received == 0)
				{
					ft_putstr(str);
					ft_putchar('\n');
					free(str);
					
					kill(g_data.pid_client, SIGUSR2);
					str = malloc(sizeof(char) * 1);
					str[0] = '\0';
				}
				g_data.char_received = 0;
				g_data.bits = 0;
			}
			g_data.sig_received = 0;
			kill(g_data.pid_client, SIGUSR1);
		}
	}
	return (0);
}