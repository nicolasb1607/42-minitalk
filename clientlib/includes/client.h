/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:23:33 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/18 16:23:37 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

typedef struct s_data
{
	int		char_to_send;
	int		bit_to_send;
	int		kill_ret;
	int		received;
	int		mask;
	int		sig;
	pid_t	pid_server;
}	t_data;

void	handler2(int sig);

#endif
