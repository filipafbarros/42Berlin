/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:25 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/28 17:49:00 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static int	acc;
	int			nb;

	(void)info;
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
		write(1, &acc, 1);
		i = 0;
		acc = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to Filipa's server.\n");
	ft_printf("Server PID: %d\n\n", getpid());
	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(100);
	return (0);
}
