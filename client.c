/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:07:12 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/02 20:01:27 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	transl_char_bit(int pid, char sign)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (sign & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i--;
	}
}

int	check_invalid_pid(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Invalid number of arguments, try again.\n");
		exit(EXIT_FAILURE);
	}
	if (check_invalid_pid(argv[1]))
	{
		ft_printf("Only numbers allowed por PIDs, try again.\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		transl_char_bit(pid, argv[2][i]);
		i++;
	}
	return (0);
}
