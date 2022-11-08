/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:48:53 by roramos           #+#    #+#             */
/*   Updated: 2022/11/08 01:34:06 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"
#include "libft.h"

char *convert_to_hex(int num, char *abc)
{
	char *hex_num;
	int size;

	size = ft_strlen(ft_itoa(num));
	hex_num = malloc(size--);
	if (!hex_num)
		return (0);
	hex_num[size--] = '\0';
	while (num >= 16)
	{
		hex_num[size--] = abc[num % 16];
		num /= 16;
	}
	hex_num[size] = abc[num];
	return hex_num;
}

int ft_print_lower_hex(int num)
{
	return (ft_print_str(convert_to_hex(num, "0123456789abcdef")));
}

int ft_print_upper_hex(int num)
{
	return (ft_print_str(convert_to_hex(num, "0123456789ABCDEF")));
}