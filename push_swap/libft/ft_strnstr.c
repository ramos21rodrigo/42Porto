/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:54:34 by roramos           #+#    #+#             */
/*   Updated: 2022/11/04 16:55:45 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	if (n == 0 && !*s2)
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] == s1[i + j] && i + j < n)
			if (!s2[++j])
				return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
