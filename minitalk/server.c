/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:25:36 by jiyokim           #+#    #+#             */
/*   Updated: 2022/06/19 17:47:34 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_initialize(void);

static void	ft_printch(unsigned char ch, pid_t clientid)
{
	if (ch)
	{
		write(1, &ch, 1);
		kill(clientid, SIGUSR1);
	}
	else
	{
		write(1, "\n", 1);
		kill(clientid, SIGUSR2);
		ft_initialize();
	}
}

static void	ft_recv_msg(int sig, siginfo_t *siginfo, void *a)
{
	static unsigned char	ch;
	static int				i;
	static pid_t			clientid;

	(void) sig;
	(void) a;
	if (!ch && !i)
		clientid = siginfo -> si_pid;
	if (clientid == siginfo -> si_pid || siginfo -> si_pid == 0)
	{
		i++;
		if (sig == SIGUSR1)
			ch |= 1 << (8 - i);
		else if (sig == SIGUSR2)
			ch &= ~(1 << (8 - i));
		if (i != 8)
			kill(clientid, SIGUSR1);
		else if (i == 8)
		{
			ft_printch(ch, clientid);
			i = 0;
		}
	}
}

static void	ft_connect(int sig, siginfo_t *siginfo, void *a)
{
	struct sigaction	act;
	pid_t				clientid;

	(void) a;
	(void) sig;
	clientid = siginfo -> si_pid;
	write(1, "client conneted\n", 16);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_recv_msg;
	if (sigaction(SIGUSR1, &act, NULL) == -1 || \
			sigaction(SIGUSR2, &act, NULL) == -1)
		ft_error("sigaction error");
	kill(clientid, SIGUSR1);
}

static void	ft_initialize(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_connect;
	sigaction(SIGUSR1, &act, NULL);
}

int	main(void)
{
	write(1, "server pid = ", 13);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	ft_initialize();
	while (1)
		pause();
	return (0);
}
