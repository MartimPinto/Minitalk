/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:42:03 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/27 14:23:52 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

volatile int	g_sign_received = 0;

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

static void	send_msg(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message was received!\n");
	g_sign_received = 1;
}

static void	end_msg_signal(pid_t pid)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	act;

	act.sa_handler = &send_msg;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	if (argc != 3)
	{
		ft_printf("Usage: ./client [PID] [message]\n");
		exit(1);
	}
	sigaction(SIGUSR1, &act, NULL);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0))
		ft_printf("Invalid PID");
	send_string(pid, argv[2]);
	send_string(pid, "\n");
	end_msg_signal(pid);
	while (!g_sign_received)
		pause ();
}
