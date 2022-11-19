/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:35:42 by roramos           #+#    #+#             */
/*   Updated: 2022/11/04 17:00:11 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*substr;
	unsigned int	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
	{
		substr = malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	substr = malloc(len * sizeof(*s) + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
