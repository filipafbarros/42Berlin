/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:01 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/28 17:47:20 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(pid_t pid, char *msg)
{
	int				i;
	unsigned char	c;

	while (*msg)
	{
		c = *msg;
		i = 8;
		while (i--)
		{
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_signal(pid, str);
	}
	else
	{
		ft_printf("Args error\n");
		exit(0);
	}
	return (0);
}
