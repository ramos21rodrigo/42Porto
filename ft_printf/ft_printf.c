/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:57:09 by roramos           #+#    #+#             */
/*   Updated: 2022/11/04 18:56:23 by roramos          ###   ########.fr       */
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
    else if (c == 'd' || c == 'i' || c == 'u')
        return (ft_print_num(va_arg(arg, int)));
    return 0;
    
}

int ft_printf(const char * format, ...)
{
    va_list args;
    int i;
    int lenght;

    va_start(args, format);

    lenght = 0;
    i = -1;
    {
    while (format[++i])
        if(format[i] != '%')
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

    printf("\n%d\n", ft_printf("ag %c %s %p %d %i %u sdasd", 'a',"rodrigo" , &c, 14 , 16, 1123456789));
    printf("\n%d", printf("ag %c %s %p %d %i %u sdasd", 'a',"rodrigo", &c , 14 , 16, 1123456789));
    return 0;
}

