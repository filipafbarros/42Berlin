/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:01 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/05 16:54:37 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_flag = 0;

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

static void	waitforsignal(void)
{
	int	i;

	i = 0;
	while (g_flag == 0)
	{
		if (i == 50)
			exit(EXIT_FAILURE);
		usleep(100);
		i++;
	}
	g_flag = 0;
}

void	send_char(unsigned char c, pid_t pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		waitforsignal();
		bit >>= 1;
	}
}

void	send_signal(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
	send_char(0, pid);
	exit(EXIT_SUCCESS);
}

void	sig_handler(int signum)
{
	g_flag = 1;
	if (signum == SIGUSR2)
		ft_printf("-------message received!!!--------\n");
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
	return (EXIT_SUCCESS);
}
