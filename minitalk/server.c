/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:25 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/27 14:52:33 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int		i;
	unsigned char	c;

	(void)context;
	i = -1;
	if (i < 0)
		i = 7;
	if (signum == SIGUSR1)
		c |= (1 << i);
	i--;
	if (i < 0 && c)
	{
		
	}
}
