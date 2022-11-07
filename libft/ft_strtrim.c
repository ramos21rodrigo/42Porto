/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:59:21 by roramos           #+#    #+#             */
/*   Updated: 2022/11/07 15:59:14 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	beg;
	size_t	final;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	beg = 0;
	while (s1[beg] && ft_set(s1[beg], set))
		beg++;
	final = ft_strlen(s1);
	while (final > beg && ft_set(s1[final - 1], set))
		final--;
	str = (char *)malloc(sizeof(*s1) * (final - beg + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (beg < final)
		str[i++] = s1[beg++];
	str[i] = 0;
	return (str);
}
