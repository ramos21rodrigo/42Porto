/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:59:21 by roramos           #+#    #+#             */
/*   Updated: 2022/11/04 17:01:35 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_initial_set_size(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (set[++i])
	{
		if (set[i] == *s1)
		{
			s1++;
			i = -1;
			count++;
		}
	}
	return (count);
}

static int	get_final_set_size(char const *s1, char const *set)
{
	int	i;
	int	count;

	if (!*s1)
		return (0);
	i = -1;
	count = 0;
	while (*s1)
		s1++;
	--s1;
	while (set[++i])
	{
		if (set[i] == *s1)
		{
			s1--;
			i = -1;
			count++;
		}
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + 1;
	str = (char *)malloc(size * sizeof(*s1));
	if (!str)
		return (NULL);
	s1 += get_initial_set_size(s1, set);
	size = ft_strlen(s1) - get_final_set_size(s1, set) + 1;
	ft_strlcpy(str, s1, size);
	return ((char *)str);
}
