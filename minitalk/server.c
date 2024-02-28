/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:25 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/28 16:59:27 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to Filipa's server.\n")
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(100);
	return (0);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static int	acc;
	int			nb;

	(void)context;
	i = 0;
	if (signum == SIGUSR1)
		nb = 0;
	else
		nb = 1;
	acc = (acc << 1) + nb;
	i++;
	if (i == 8)
	{
		ft_putchar(acc, STDOUT_FILENO);
		i = 0;
		acc = 0;
	}
}
