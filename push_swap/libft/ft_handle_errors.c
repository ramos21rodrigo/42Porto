/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:27:32 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 19:21:00 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_handle_errors(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
