/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:57:09 by roramos           #+#    #+#             */
/*   Updated: 2022/11/17 14:24:57 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	find_convertion(char c, va_list arg)
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
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	va_start(args, format);
	length = 0;
	i = -1;
	{
		while (format[++i])
		{
			if (format[i] != '%')
			{
				length += ft_print_chr(format[i]);
			}
			else
			{
				length += find_convertion(format[++i], args);
			}
		}
	}
	va_end(args);
	return (length);
}
