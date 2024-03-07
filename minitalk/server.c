/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:25 by fibarros          #+#    #+#             */
/*   Updated: 2024/03/06 15:13:19 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	signal_handler(int signum, siginfo_t *info, void *context)
// {
// 	static int				i;
// 	static unsigned char	bit;
// 	static pid_t			client_pid;

// 	(void)context;
// 	// (void)info;
// 	client_pid = 0;
// 	i = 0;
// 	bit = 0;
// 	if (!client_pid)
// 		client_pid = info->si_pid;
// 	if (signum == SIGUSR1)
// 		i |= (0x01 << bit);
// 	bit++;
// 	if (bit == 8)
// 	{
// 		write(1, &i, 1);
// 		bit = 0;
// 		i = 0;
// 		kill(info->si_pid, SIGUSR2);
// 	}
// }

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	bit;
	static pid_t			client_pid;

	(void)context;
	// (void)info;
	client_pid = 0;
	i = 0;
	bit = 0;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signum == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

static void	sig_init(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	// sigaddset(&sa.sa_mask, SIGUSR1);
	// sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
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

	// signal_handler(0, NULL, NULL);
	while (1)
	{
		sig_init();
	}
	return (0);
}
