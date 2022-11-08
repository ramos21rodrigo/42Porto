/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:21:06 by roramos           #+#    #+#             */
/*   Updated: 2022/11/08 12:49:47 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *a(char *text)
{
	int i;
	int j;
	char *str;

	i = 0;
	while (text[i - 1] != '\n' && text[i] != '\0')
		i++;
	str = malloc(i);
	i = 0;
	while (text[i - 1] != '\n' && text[i] != '\0')
	{
		str[i] = text[i];
		i++;
	}
	while (text[(j++) - 1] != '\n')
		text[j] = text[i + j];
	return (str);
}

char *get_next_line(int fd)
{
	char *buffer;
	static char *text;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);
	if (!text)
	{
		text = "";
		buffer = malloc(BUFFER_SIZE * sizeof(char));
		if (!buffer)
			return (NULL);
		while (read(fd, buffer, BUFFER_SIZE) != '\0')
			text = ft_strjoin(text, buffer);
	}
	return (a(text));
}

int main()
{
	int fd = open("a.txt", O_RDONLY);
	int i = 4;
	while (i--)
	{
		printf("%s", get_next_line(fd));
	}
	return 0;
}
