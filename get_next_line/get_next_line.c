/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:21:06 by roramos           #+#    #+#             */
/*   Updated: 2022/11/10 21:14:08 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_free(char *text, char *buf)
{
	char *temp;

	temp = ft_strjoin(text, buf);
	free(text);
	return (temp);
}

char *read_first_line(int fd, char *text)
{
	char *buffer;
	int bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(text, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		text = ft_strjoin(text, buffer);
	}
	free(buffer);
	return (text);
}

char *get_line(char *text)
{
	int i;
	char *str;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	str = malloc(sizeof(*text) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		str[i] = text[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *clean_first_line(char *text)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	str = malloc(sizeof(*text) * (ft_strlen(text) - i + 1));
	if (!str)
		return (NULL);
	while (text[++i])
		str[j++] = text[i];
	str[j] = '\0';
	free(text);
	return (str);
}

char *get_next_line(int fd)
{
	char *output_text;
	static char *text;

	if (BUFFER_SIZE <= 0 || fd <= 0 || read(fd, NULL, 0) != 0)
		return (NULL);
	if (!text)
		text = "\0";
	text = read_first_line(fd, text);
	if (!*text)
		return (NULL);
	output_text = get_line(text);
	text = clean_first_line(text);
	return (output_text);
}

int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *a;

	while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	}

	// printf("%s", get_next_line(fd));

	return 0;
}
