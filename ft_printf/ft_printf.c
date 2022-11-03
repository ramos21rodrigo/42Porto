/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:57:09 by roramos           #+#    #+#             */
/*   Updated: 2022/11/03 18:53:49 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printft.h"

static int find_convertion(char c, va_list arg)
{
    if (c == 'c')
        return (ft_print_chr(va_arg(arg, int)));
    else if (c == 's')
        return (ft_print_str(va_arg(arg, char *)));
    else if (c == 'p')
        return (ft_print_ptr(va_arg(arg, unsigned long long)));
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
    while (format[++i])
    {
        if(format[i] != '%')
            lenght += ft_print_chr(format[i]);
        else
            lenght += find_convertion(format[++i], args);
    }

    va_end(args);    
    return 0;
}

int main()
{
    int a = 1;

    ft_printf("ag %c %s %p sdasd", 'a',"rodrigo" , &a);
    printf("\n");
    printf("ag %c %s %p sdasd", 'a',"rodrigo", &a);
    return 0;
}

