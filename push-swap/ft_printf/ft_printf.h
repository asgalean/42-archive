/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:54:56 by asgalean          #+#    #+#             */
/*   Updated: 2025/01/09 18:55:29 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr(int num);
int	ft_putnbru(unsigned int num);
int	ft_putstr(char *str);
int	ft_puthex(int caps, unsigned int num);
int	ft_putptr(int flag, unsigned long long num);
int	ft_printf(char const *str, ...);

#endif
