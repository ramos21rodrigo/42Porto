/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:13:06 by roramos           #+#    #+#             */
/*   Updated: 2022/11/04 18:40:37 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H
# define PRINTFT_H

# include <stdarg.h>

int ft_print_str(char *s);
int ft_print_chr(char c);
int ft_print_ptr(unsigned long long ptr);
int ft_print_num(int num);
int ft_print_unum(int unsigned num);


#endif