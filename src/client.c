/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:42:03 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/27 14:24:36 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_string(pid_t pid, char *str)
{
	int		bits;
	char	c;
	int		batch_count;

	batch_count = 0;
	while (*str)
	{
		c = *str;
		bits = 8;
		while (bits--)
		{
			if (c >> bits & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(800);
		}
		batch_count++;
		if (batch_count == BATCH_SIZE || *str++ == '\0')
		{
			usleep(10000);
			batch_count = 0;
		}	
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [PID] [message]\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0))
		ft_printf("Invalid PID\n");
	send_string(pid, argv[2]);
	send_string(pid, "\n");
}
