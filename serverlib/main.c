/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:37:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/18 15:49:11 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/server.h"

t_data	g_data;

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
}

void	receive_char(int sig, siginfo_t *siginfo, void *context)
{
	g_data.pid_client = siginfo->si_pid;
	(void) context;
	if (sig == SIGUSR1 && g_data.bits < 8)
		g_data.char_received |= (1 << (7 - g_data.bits++));
	if (sig == SIGUSR2 && g_data.bits < 8)
		g_data.char_received &= ~(1 << (7 - g_data.bits++));
	g_data.sig_received = 1;
}

void	print_msg(void)
{
	ft_putstr(g_data.msg);
	ft_putchar('\n');
	free(g_data.msg);
	kill(g_data.pid_client, SIGUSR2);
	g_data.msg = malloc(sizeof(char) * 1);
	g_data.msg [0] = '\0';
}

void	append_msg(void)
{
	if (g_data.bits == 8)
	{
		g_data.msg = ft_strjoin(g_data.msg, g_data.char_received);
		if (g_data.char_received == 0)
			print_msg();
		g_data.char_received = 0;
		g_data.bits = 0;
	}
	g_data.sig_received = 0;
	kill(g_data.pid_client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	g_data.char_received = 0;
	g_data.bits = 0;
	sa.sa_sigaction = receive_char;
	sa.sa_flags = SA_SIGINFO;
	g_data.msg = malloc(sizeof(char) * 1);
	g_data.msg [0] = '\0';
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	print_pid();
	while (1)
		if (g_data.sig_received == 1)
			append_msg();
	return (0);
}
