/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:45 by roramos           #+#    #+#             */
/*   Updated: 2022/09/04 02:07:50 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, unsigned int n)
{
	unsigned char	*dest;
	unsigned char	*srce;

	dest = dst;
	srce = src;
	while (n--)
		*dest++ = *srce++;
	return (dst);
}
