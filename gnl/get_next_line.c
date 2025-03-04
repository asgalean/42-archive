/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:08:06 by asgalean          #+#    #+#             */
/*   Updated: 2025/01/13 12:08:17 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line_getter(char **src)
{
	char	*dest;
	char	*new_src;
	int		i;
	int		rem_len;

	dest = (char *)malloc(sizeof(char) * (ft_line_len((*src)) + 2));
	if (!dest)
		return (NULL);
	i = ft_line_copy(dest, *src);
	rem_len = ft_strlen(&(*src)[i]);
	new_src = NULL;
	if (rem_len > 0)
	{
		new_src = (char *)malloc(sizeof(char) * (rem_len + 1));
		if (!new_src)
		{
			free(dest);
			return (NULL);
		}
		ft_strcpy(new_src, &(*src)[i]);
	}
	free(*src);
	*src = new_src;
	return (dest);
}

char	*ft_stack(char *dest, char *src, int r_bytes)
{
	char	*new_dest;
	int		i;
	int		j;

	new_dest = (char *)malloc(sizeof(char) * (ft_strlen(dest) + r_bytes + 1));
	if (!new_dest)
	{
		free(dest);
		return (NULL);
	}
	i = 0;
	while (dest && dest[i])
	{
		new_dest[i] = dest[i];
		i++;
	}
	j = -1;
	while (++j < r_bytes)
		new_dest[i + j] = src[j];
	new_dest[i + j] = '\0';
	free(dest);
	return (new_dest);
}

char	*ft_read_dump(char *buffer, char *load, int fd)
{
	int	r_bytes;	

	r_bytes = 1;
	while (r_bytes > 0)
	{
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[r_bytes] = '\0';
		load = ft_stack(load, buffer, r_bytes);
		if (!load)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(load, '\n'))
			break ;
	}
	return (load);
}

char	*get_next_line(int fd)
{
	static char	*load = NULL;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	load = ft_read_dump(buffer, load, fd);
	if (!load)
		return (NULL);
	free(buffer);
	if (!load || load[0] == '\0')
	{
		free(load);
		load = NULL;
		return (NULL);
	}
	return (ft_line_getter(&load));
}
