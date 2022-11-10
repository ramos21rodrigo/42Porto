/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:51:36 by roramos           #+#    #+#             */
/*   Updated: 2022/11/10 14:47:31 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_get_index_of(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
    printf("%s", s1);
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j])
			if (!s2[++j])
				return (i);
		i++;
	}
	return (-1);
}

char	*read_first_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

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
	return (text);
}

char	*get_line(char *text)
{
	int		i;
	char	*str;

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

char	*clean_first_line(char *text)
{
	int		i;
	int		j;
	char	*str;

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
	return (str);
}

char	*get_next_line(int fd)
{
	char		*output_text;
	static char	**text;
    int         index;

	if (BUFFER_SIZE <= 0 || fd <= 0 || read(fd, NULL, 0) != 0)
		return (NULL);
    text = malloc(1 * sizeof(char *));
    if (!text)
        return (NULL);
    if (!text[0])
		text[0] = "";
    index = ft_get_index_of(text[0], ft_itoa(fd));
    if (index == -1)
    {
        text[0] = ft_strjoin(text[0], ft_itoa(fd));
        text[0] = ft_strjoin(text[0], " ");
    }
    printf("i%d", index);
    return (NULL);
	text[0] = read_first_line(fd, text[0]);
	if (!*text[0])
		return (NULL);
	output_text = get_line(text[0]);
	text[0] = clean_first_line(text[0]);
	return (output_text);
}

int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *a;

	/* while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	} */

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	return 0;
}