/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:01 by fibarros          #+#    #+#             */
/*   Updated: 2024/03/06 14:19:50 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_control;

void send_signal(pid_t pid, char c)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (kill(pid, 0) < 0)
			{
				ft_printf("error sending signal to pid %d\n", pid);
				exit(0);
			}
		g_control = 0;
		if (bit & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit >>= 1;
		usleep(100);
	}
}

static int	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signal(pid, str[i]);
		i++;
	}
	send_signal(pid, 0);
	return (1);
}

void sig_handler(int signum)
{
	if (signum == SIGUSR1)
		g_control = 1;
	else if (signum == SIGUSR2)
		{
			ft_printf("Message received!\n");
			exit(0);
		}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3 || !argv[2])
	{
		ft_printf("error with the arguments!");
		exit(0);
	}
	signal(SIGUSR1, &sig_handler);
	signal(SIGUSR2, &sig_handler);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (!send_str(pid, str))
		{
			ft_printf("error with sending signal, client side");
			exit(0);
		}
	while (1)
		sleep(1);
}
