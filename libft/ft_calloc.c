/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:31:13 by roramos           #+#    #+#             */
/*   Updated: 2022/10/12 19:54:34 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (pointer == NULL)
		return (pointer);
	ft_bzero(pointer, size * count);
	return (pointer);
}
