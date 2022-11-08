/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:13:06 by roramos           #+#    #+#             */
/*   Updated: 2022/11/08 01:40:06 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H
#define PRINTFT_H

#include <stdarg.h>

int ft_print_str(char *s);
int ft_print_chr(char c);
int ft_print_ptr(unsigned long long ptr);
int ft_print_num(int num);
int ft_print_unum(int unsigned num);
int ft_print_lower_hex(int num);
int ft_print_upper_hex(int num);
int ft_print_percent();

#endif