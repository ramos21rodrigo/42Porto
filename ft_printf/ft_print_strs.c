/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:15:12 by roramos           #+#    #+#             */
/*   Updated: 2022/11/04 15:30:27 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"
#include "libft.h"

int ft_print_str(char *s)
{
    return (write(1, s, ft_strlen(s)));
}

int ft_print_chr(char c)
{
    return (write(1, &c, 1));
}