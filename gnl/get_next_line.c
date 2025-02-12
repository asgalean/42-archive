/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:58:58 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/03/21 11:48:21 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.c"
#define BUFFER_SIZE 20

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_read(fd, str);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	line = get_the_line(str);
	str = get_str(str);
	return (line);
}

char	*get_read(int fd, char *str)
{
	int		byte;
	char	*buf;

	byte = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(str, '\n') && byte != 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[byte] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_the_line(char *str)
{
	int		i;
	char	*buf;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	buf = (char *)malloc(sizeof(char) * (i + 2));
	if (!buf)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		buf[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char	*get_str(char *str)
{
	int		i;
	int		j;
	char	*a;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	a = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 2));
	if (!a)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		a[j++] = str[i++];
	free(str);
	a[j] = '\0';
	return (a);
}

/*int	main(void)
{
	int fd;
    char *tab;
    fd = open("test.txt", O_RDONLY);
    tab = get_next_line(fd);
    printf("%s", tab);
    free(tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    close(fd);
	return (0);
}*/
