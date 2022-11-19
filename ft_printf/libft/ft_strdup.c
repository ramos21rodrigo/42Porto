/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:40:40 by roramos           #+#    #+#             */
/*   Updated: 2022/10/12 19:54:02 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	int		size;

	size = ft_strlen(s1) + 1;
	pointer = malloc(size * sizeof(char));
	if (pointer == NULL)
		return (NULL);
	ft_strlcpy(pointer, s1, size);
	return (pointer);
}
