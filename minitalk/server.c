/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:15:39 by roramos           #+#    #+#             */
/*   Updated: 2022/11/29 15:41:48 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int signum)
{
	static int				bits = -1;
	static unsigned char	c;

	if (bits < 0)
		bits = 7;
	if (signum == SIGUSR1)
		c |= (1 << bits);
	bits--;
	if (bits < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Server pid: %d\n\n", getpid());
	while (true)
	{
		signal(SIGUSR1, handle_sigusr);
		signal(SIGUSR2, handle_sigusr);
	}
	return (EXIT_SUCCESS);
}
