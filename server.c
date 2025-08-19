/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:31:32 by anakrash          #+#    #+#             */
/*   Updated: 2024/11/22 16:14:00 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static char	char_buffer = 0;
	static int	bit_count = 0;

	if (signum == SIGUSR1)
		char_buffer <<= 1;
	else if (signum == SIGUSR2)
		char_buffer = (char_buffer << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &char_buffer, 1);
		char_buffer = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
