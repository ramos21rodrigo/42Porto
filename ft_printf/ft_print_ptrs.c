/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:57 by roramos           #+#    #+#             */
/*   Updated: 2022/11/04 16:21:39 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printft.h"

int	ft_ptr_len(intptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(intptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_chr(num + '0');
		else
			ft_print_chr(num - 10 + 'a');
	}
}

int ft_print_ptr(unsigned long long ptr)
{
	write(1, "0x", 2);
	if (ptr == 0)
		return(write(1, "0", 1) + 2);
    ft_put_ptr(ptr);
	return (ft_ptr_len(ptr) + 2);
}