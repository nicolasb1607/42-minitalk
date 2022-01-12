/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:40:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/12 20:12:14 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/client.h"

int main(int ac, char **av)
{
	pid_t pid;
	char **str;
	
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = str_to_byte(av[2]);
		send_str(str,pid);
		free_data(str);
	}
	return (0);
}