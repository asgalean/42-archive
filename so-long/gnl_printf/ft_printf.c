/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:46:07 by asgalean          #+#    #+#             */
/*   Updated: 2025/01/09 13:46:13 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_print_filter(va_list list, char w)
{
	int		total;
	char	a;

	total = 0;
	if (w == 'd' || w == 'i')
		total += ft_putnbr(va_arg(list, int));
	if (w == '%')
		total += write(1, "%", 1);
	if (w == 'c')
	{
		a = va_arg(list, int);
		total += write(1, &a, 1);
	}
	if (w == 's')
		total += ft_putstr(va_arg(list, char *));
	if (w == 'u')
		total += ft_putnbru(va_arg(list, unsigned int));
	if (w == 'x')
		total += ft_puthex(0, va_arg(list, unsigned int));
	if (w == 'X')
		total += ft_puthex(1, va_arg(list, unsigned int));
	if (w == 'p')
		total += ft_putptr(0, va_arg(list, unsigned long long));
	return (total);
}

int	ft_printf(char const *string, ...)
{
	va_list	list;
	int		i;
	int		total;

	total = 0;
	i = 0;
	va_start(list, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			total += ft_print_filter(list, string[i + 1]);
			i += 2;
		}
		else
		{
			total += write(1, &string[i], 1);
			i++;
		}
	}
	va_end(list);
	return (total);
}
