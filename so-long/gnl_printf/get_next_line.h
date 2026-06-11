/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:09:02 by asgalean          #+#    #+#             */
/*   Updated: 2025/01/13 12:09:03 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

int		ft_line_len(char *str);
int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
int		ft_line_copy(char *dest, char *src);
void	ft_strcpy(char *dest, char *src);
char	*ft_line_getter(char **src);
char	*ft_stack(char *dest, char *src, int r_bytes);
char	*ft_read_dump(char *buffer, char *load, int fd);
char	*get_next_line(int fd);

#endif
