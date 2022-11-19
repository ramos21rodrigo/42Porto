/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:45 by roramos           #+#    #+#             */
/*   Updated: 2022/11/04 18:21:14 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, unsigned int n)
{
	unsigned char	*dest;
	unsigned char	*srce;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	srce = src;
	while (n--)
		*dest++ = *srce++;
	return (dst);
}
