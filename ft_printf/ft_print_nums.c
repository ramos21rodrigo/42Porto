/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:32:02 by roramos           #+#    #+#             */
/*   Updated: 2022/11/04 18:42:59 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int ft_print_num(int num)
{
    ft_putnbr_fd(num, 1);
    return(ft_strlen(ft_itoa(num)));
}

int ft_print_unum(unsigned int num)
{
    return (ft_print_num(num));
}