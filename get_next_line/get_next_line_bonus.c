/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:51:36 by roramos           #+#    #+#             */
/*   Updated: 2022/11/10 21:33:08 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int ft_get_index_of(char *s1, char *s2)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	k = 0;
	while (s1[i])
	{
		if (s1[i] == ' ')
			k++;
		j = 0;
		while (s2[j] == s1[i + j])
			if (!s2[++j])
				return (k + 1);
		i++;
	}
	return (-1);
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
			return (NULL);
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
	static char **text;
	int index;
	char *itoa;

	if (BUFFER_SIZE <= 0 || fd <= 0 || read(fd, NULL, 0) != 0)
		return (NULL);
	while (!text)
	{
		text = malloc(sizeof(char *));
		if (!text)
			return (NULL);
		text[0] = "\0";
	}
	itoa = ft_itoa(fd);
	index = ft_get_index_of(text[0], itoa);
	if (index == -1)
	{
		text[0] = ft_strjoin(text[0], itoa);
		text[0] = ft_strjoin(text[0], " ");
		index = ft_get_index_of(text[0], itoa);
		text[index] = "\0";
	}
	free(itoa);
	text[index] = read_first_line(fd, text[index]);
	if (!*text[index])
		return (NULL);
	output_text = get_line(text[index]);
	text[index] = clean_first_line(text[index]);
	return (output_text);
}

int main()
{
	int fd = open("a.txt", O_RDONLY);
	int fdb = open("b.txt", O_RDONLY);
	int fdc = open("c.txt", O_RDONLY);
	char *a;

	/* while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	} */

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fdc));
	printf("%s", get_next_line(fdc));
	printf("%s", get_next_line(fdc));
	printf("%s", get_next_line(fdb));
	printf("%s", get_next_line(fdb));
	printf("%s", get_next_line(fdc));
	printf("%s", get_next_line(fdc));
	printf("%s", get_next_line(fd));

	return 0;
}