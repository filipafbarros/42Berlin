/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:22:14 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/03 16:23:55 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static char	bit;

	(void)context;
	if (signum == SIGUSR1)
		bit += 1 << (7 - i);
	i++;
	if (i == 8 && bit)
	{
		ft_putchar_fd(bit, 1);

		if (kill(info->si_pid, SIGUSR2) == -1)
		{
			ft_printf("Server failed to send signal back to client");
			exit(0);
		}
		bit = 0;
		i = 0;
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
	else if (sigaction(SIGUSR2, &sa, NULL) == -1)
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
