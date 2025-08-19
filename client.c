/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:31:27 by anakrash          #+#    #+#             */
/*   Updated: 2024/11/22 16:21:22 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if (bit == 1)
		kill(pid, SIGUSR2);
	usleep(700);
}

void	send_char(int pid, char ch)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(pid, (ch >> i) & 1);
		i--;
	}
}

void	send_message(int pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (argc != 3)
		return (1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid == 0)
		return (1);
	message = argv[2];
	send_message(server_pid, message);
	return (0);
}
