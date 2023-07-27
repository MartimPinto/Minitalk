/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:37:38 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/27 14:24:17 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static void	set(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;

	(void)context;
	if (!c)
		c = 0;
	if (!bit)
		bit = 0;
	if (sig == SIGUSR1)
		c |= 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		if (!c)
			kill(info -> si_pid, SIGUSR1);
		else
			write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	sig.sa_sigaction = &set;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	pid = getpid();
	if (pid == -1)
	{
		ft_printf("Invalid PID\n");
		exit(1);
	}
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
