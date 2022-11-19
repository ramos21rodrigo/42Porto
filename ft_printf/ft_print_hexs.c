/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:48:53 by roramos           #+#    #+#             */
/*   Updated: 2022/11/17 13:57:54 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	convert_to_hex(unsigned int num, int word)
{
	int		i;
	int		j;
	int		temp;
	char	hex[100];

	i = 1;
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + word;
		hex[i++] = temp;
		num /= 16;
	}
	j = --i;
	while (j > 0)
		ft_print_chr(hex[j--]);
	return (i);
}

int	ft_print_lower_hex(int num)
{
	if (num == 0)
		return (ft_print_chr('0'));
	return (convert_to_hex(num, 87));
}

int	ft_print_upper_hex(int num)
{
	if (num == 0)
		return (ft_print_chr('0'));
	return (convert_to_hex(num, 55));
}
