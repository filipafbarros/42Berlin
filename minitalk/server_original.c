/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:25 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/04 16:21:19 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	if (signum == SIGUSR1)
		c += 1 << (7 - i);
	i++;
	if (i == 8 && c)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		i = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf("Catastrophic fail - did not send SIGUSR1");
		return ;
	}
}

static void	sig_init(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Failed to register SIGUSR1 signal handler\n");
		exit(0);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Failed to register SIGUSR2 signal handler\n");
		exit(0);
	}
}

int	main(void)
{
	ft_printf("Welcome to Filipa's server.\n");
	ft_printf("Server PID: %d\n\n", getpid());
	sig_init();
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
