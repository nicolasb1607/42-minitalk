/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:37:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/12 20:31:37 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/server.h"

void handle_sigusr1()
{
	printf("1\n");
}

void handle_sigusr2()
{
	printf("0\n");
}

void print_pid()
{
    pid_t pid;
	
    pid = getpid();
    printf("PID : %d\n", pid);
}

int main()
{		
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);

	print_pid();
	while (1)
	{
		
	}
	return (0);
}