/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:01 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/05 15:11:51 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("error with the number of arguments!");
		exit(1);
	}
	while (av[1][i])
	{
		if (!(ft_isdigit(av[1][i++])))
		{
			ft_printf("Invalid pid!");
			exit(1);
		}
	}
	if (*av[2] == 0)
	{
		ft_printf("empty message!");
		exit(1);
	}
}

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
			usleep(300);
			c <<= 1;
		}
		str++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Things are happening!\n");
}

void	sig_config(void)
{
	struct sigaction	sa;

	sa.sa_handler = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("catastrophic failure with SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("catastrophic failure with SIGUSR2");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	sig_config();
	send_signal(pid, str);
	send_signal(pid, "\n");
	ft_printf("-------message received!!!--------");
	return (EXIT_SUCCESS);
}
