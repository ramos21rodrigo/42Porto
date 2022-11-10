/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:32:02 by roramos           #+#    #+#             */
/*   Updated: 2022/11/08 11:13:43 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static int digit_count(unsigned int i)
{
	int count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static char *ft_uitoa(unsigned int n)
{
	char *str;
	unsigned int i;
	unsigned int nb;

	nb = n;
	i = digit_count(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (0);
	str[i--] = 0;
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

int ft_print_unum(unsigned int unum)
{
	return (write(1, ft_uitoa(unum), ft_strlen(ft_uitoa(unum))));
}

int ft_print_num(int num)
{
	ft_putnbr_fd(num, 1);
	return (ft_strlen(ft_itoa(num)));
}
