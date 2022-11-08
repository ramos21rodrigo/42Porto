/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:15:12 by roramos           #+#    #+#             */
/*   Updated: 2022/11/08 01:40:23 by roramos          ###   ########.fr       */
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

int ft_print_percent()
{
	return (write(1, &"%", 1));
}