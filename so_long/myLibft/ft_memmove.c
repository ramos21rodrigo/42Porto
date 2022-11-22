/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:18:11 by roramos           #+#    #+#             */
/*   Updated: 2022/10/10 11:13:57 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned int n)
{
	unsigned int		i;
	unsigned char		*dest;
	const unsigned char	*sorc;

	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	i = 0;
	if (!dest && !sorc)
		return (NULL);
	if (sorc < dest)
	{
		while (++i <= n)
			dest[n - i] = sorc[n - i];
		return (dst);
	}
	while (n-- > 0)
		*dest++ = *sorc++;
	return (dst);
}
