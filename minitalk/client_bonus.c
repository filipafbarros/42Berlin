/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:20:35 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/03 16:19:31 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_signal(pid_t pid, char *str)
{
	unsigned char	c;
	int				bits;

	while (*str)
	{
		c = *str;
		bits = 8;
		while (bits--)
		{
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(250);
			c <<= 1;
		}
		str++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("Message received!\n");
		exit(EXIT_SUCCESS);
	}
}

void	config_sig(void)
{
	struct sigaction	sa;

	sa.sa_handler = &sig_handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("fail with SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("fail with SIGUSR2");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3 || !argv[2])
	{
		ft_printf("error with the arguments!");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	config_sig();
	send_signal(pid, str);
	send_signal(pid, "\n");
	return (EXIT_SUCCESS);
}
