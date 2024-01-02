/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:07:27 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/02 13:31:48 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	static int	bin;
	static char	chr;

	if (bin < 8)
	{
		if (sig == SIGUSR1)
			chr += (1 << (7 - bin));
		bin++;
	}
	if (bin == 8)
	{
		ft_printf("%c", chr);
		chr = 0;
		bin = 0;
	}
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
