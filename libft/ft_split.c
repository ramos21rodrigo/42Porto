/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:42:18 by roramos           #+#    #+#             */
/*   Updated: 2022/10/17 17:11:37 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_counter(char const *s, char c)
{
	int	words;
	int	flag;

	words = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			words++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (words);
}

static int	letters_in_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	**str;
	int		size;

	i = 0;
	j = -1;
	word = words_counter(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = letters_in_word(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str)
			return (NULL);
		i += size;
	}
	str[j] = 0;
	return (str);
}
