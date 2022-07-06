/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:52 by jiyokim           #+#    #+#             */
/*   Updated: 2022/06/20 19:40:19 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

static int	ft_str2bit(void)
{
	static int	bit_index;
	static int	str_index;

	bit_index++;
	if (bit_index > 8)
	{
		bit_index = 1;
		str_index++;
	}
	if (g_info.str[str_index])
		return (g_info.str[str_index] & (1 << (8 - bit_index)));
	return (0);
}

static void	ft_send(int sig)
{
	int	bit;

	bit = 0;
	if (sig == SIGUSR2)
		exit(0);
	bit = ft_str2bit();
	if (bit)
		kill(g_info.server_pid, SIGUSR1);
	else if (bit == 0)
		kill(g_info.server_pid, SIGUSR2);
}

static void	ft_connect(int sig)
{
	int	bit;

	(void) sig;
	bit = 0;
	write(1, "Server connected\n", 17);
	if (signal(SIGUSR1, ft_send) == SIG_ERR \
			| signal(SIGUSR2, ft_send) == SIG_ERR)
		ft_error("signal() error");
	bit = ft_str2bit();
	if (bit)
		kill(g_info.server_pid, SIGUSR1);
	else if (bit == 0)
		kill(g_info.server_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("WRONG!!\n", 1);
		ft_putstr_fd("[Usage]: ./client [ServerPID] [Message]", 1);
		return (0);
	}
	g_info.server_pid = ft_atoi(argv[1]);
	if (g_info.server_pid < 100 || g_info.server_pid > 99998)
		return (0);
	g_info.str = (unsigned char *)argv[2];
	if (signal(SIGUSR1, ft_connect) == SIG_ERR)
		ft_error("signal error");
	kill(g_info.server_pid, SIGUSR1);
	while (1)
		pause();
	return (0);
}
