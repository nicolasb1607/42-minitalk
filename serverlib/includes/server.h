/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:14:42 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/18 13:15:34 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

# include <stdio.h> // A SUPPRIMER 

typedef struct s_data
{
	pid_t	pid_client;
	int		bits;
	char	char_received;
	char	*msg;
	int		sig_received;
}	t_data;

#endif
