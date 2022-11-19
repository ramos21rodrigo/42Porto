/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:32:02 by roramos           #+#    #+#             */
/*   Updated: 2022/11/18 17:46:46 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	digit_count(unsigned int i)
{
	int	count;

	count = 0;
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

int	ft_uitoa(unsigned int n)
{
	char			*str;
	int				length;
	unsigned int	i;
	unsigned int	nb;

	nb = n;
	i = digit_count(nb);
	if (nb == 0)
		return (write(1, "0", 1));
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (0);
	str[i--] = 0;
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	length = write(1, str, ft_strlen(str));
	free(str);
	return (length);
}

int	ft_print_unum(unsigned int unum)
{
	return (ft_uitoa(unum));
}

int	ft_print_num(int num)
{
	char	*num_to_str;
	int		length;

	ft_putnbr_fd(num, 1);
	num_to_str = ft_itoa(num);
	length = ft_strlen(num_to_str);
	free (num_to_str);
	return (length);
}
