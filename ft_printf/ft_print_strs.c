/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:15:12 by roramos           #+#    #+#             */
/*   Updated: 2022/11/03 18:55:59 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"
#include "libft.h"

int ft_print_str(char *s)
{
    ft_putstr_fd(s, 1);
    return (ft_strlen(s));
}

int ft_print_chr(char c)
{
    ft_putchar_fd(c, 1);
    return (1);
}

int ft_print_ptr(unsigned long long p)
{
    ft_putstr_fd("0x", 1);
    if (p == 0)
	{
        write(1, "0", 1);
        return (3);
    }
}   