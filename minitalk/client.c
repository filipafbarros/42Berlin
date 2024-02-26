/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:41:01 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/26 16:48:10 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t* info, void* context)
{
	(void)context;
	
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	
}
