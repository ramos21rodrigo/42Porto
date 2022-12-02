/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:15:39 by roramos           #+#    #+#             */
/*   Updated: 2022/11/29 16:41:20 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bits = -1;
	static unsigned char	c;

	(void)ucontent;
	if (bits < 0)
		bits = 7;
	if (signum == SIGUSR1)
		c |= (1 << bits);
	bits--;
	if (bits < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			handle_errors("Failed to send SIGUSR1");
	}
}

void	create_signal(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	ft_printf("Server pid: %d\n", getpid());
	create_signal();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
