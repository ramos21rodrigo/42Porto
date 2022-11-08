/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:21:06 by roramos           #+#    #+#             */
/*   Updated: 2022/11/08 16:06:33 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *separate_by_line(char *text, int starting_value)
{
	int i;
	char *str;

	i = 0;
	if (!text[starting_value + i])
		return (NULL);
	while (text[starting_value + i] != '\n' && text[starting_value + i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (text[starting_value + i] != '\n' && text[starting_value + i])
	{
		str[i] = text[starting_value + i];
		i++;
	}
	if (text[starting_value + i])
		str[i] = '\n';
	return (str);
}

char *get_next_line(int fd)
{
	char *buffer;
	char *output_text;
	static char *text;
	static int starting_value;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);
	if (!text)
	{
		starting_value = 0;
		text = "";
		buffer = malloc(BUFFER_SIZE * sizeof(char));
		if (!buffer)
			return (NULL);
		while (read(fd, buffer, BUFFER_SIZE) != '\0')
			text = ft_strjoin(text, buffer);
	}
	output_text = separate_by_line(text, starting_value);
	if(!output_text)
		return (NULL);
	starting_value += ft_strlen(output_text);
	return (output_text);
}

/*  int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *a;

	while((a = get_next_line(fd)))
		printf("%s", a);
	
	return 0;
} */
 