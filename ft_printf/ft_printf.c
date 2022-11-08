/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:57:09 by roramos           #+#    #+#             */
/*   Updated: 2022/11/08 01:39:48 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printft.h"

static int find_convertion(char c, va_list arg)
{
	if (c == 'c')
		return (ft_print_chr((va_arg(arg, int))));
	else if (c == 's')
		return (ft_print_str(va_arg(arg, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(arg, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (ft_print_num(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_print_unum(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_print_lower_hex(va_arg(arg, int)));
	else if (c == 'X')
		return (ft_print_upper_hex(va_arg(arg, int)));
	else if (c == '%')
		return (ft_print_percent());
	return 0;
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int lenght;

	va_start(args, format);

	lenght = 0;
	i = -1;
	{
		while (format[++i])
			if (format[i] != '%')
				lenght += ft_print_chr(format[i]);
			else
				lenght += find_convertion(format[++i], args);
	}

	va_end(args);
	return lenght;
}

int main()
{
	int c;

	printf("\n%d\n", ft_printf("ag %c %s %p %d %i %u %x %X %% sdasd", 'a', "rodrigo", &c, 14, 16, -123456789, 1364435, 45982743));
	printf("\n%d", printf("ag %c %s %p %d %i %u %x %X %% sdasd", 'a', "rodrigo", &c, 14, 16, -123456789, 1364435, 45982743));
	return 0;
}
