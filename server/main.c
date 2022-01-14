/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:37:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/14 16:36:15 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/server.h"


void print_pid()
{
	pid_t pid;

	pid = getpid();
	printf("PID : %d\n", pid);
}

int main()
{
	struct sigaction sa;
	
	sa.sa_sigaction = receive_char;
	sa.sa_flags = SA_SIGINFO;
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	print_pid();
	while (1)
	{
	}
	return (0);
}