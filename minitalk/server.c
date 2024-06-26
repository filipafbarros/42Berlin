/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:25 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/05 16:53:06 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signum, siginfo_t *info, void *context);

static void	print_char(char c, int i, int pid)
{
	ft_putchar_fd(c, 1);
	if (i == 0)
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_printf("Failed to send signal");
	}
	if (i == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_printf("Failed to send signal");
	}
	signal_handler(0, NULL, NULL);
}

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static char	bit;

	(void)context;
	if (signum == 0)
	{
		i = 0;
		bit = 0;
		return ;
	}
	if (signum == SIGUSR2)
		i++;
	if (signum == SIGUSR1)
	{
		bit += 1 << (7 - i);
		++i;
	}
	if (i == 8)
	{
		if (bit == 0)
			return (print_char('\n', 0, info->si_pid));
		return (print_char(bit, 1, info->si_pid));
	}
	kill(info->si_pid, SIGUSR1);
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
