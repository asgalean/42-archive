/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:46:36 by asgalean          #+#    #+#             */
/*   Updated: 2025/01/09 13:46:47 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr(int num)
{
	int	n;
	int	total;

	total = 0;
	if (num == -2147483648)
		total = write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			total += write(1, "-", 1);
			num = -num;
		}
		if (num >= 10)
			total += ft_putnbr(num / 10);
		n = (num % 10) + '0';
		total += write(1, &n, 1);
	}
	return (total);
}

int	ft_putnbru(unsigned int num)
{
	unsigned int	n;
	int				total;

	total = 0;
	if (num >= 10)
		total += ft_putnbr(num / 10);
	n = (num % 10) + '0';
	total += write(1, &n, 1);
	return (total);
}

int	ft_putstr(char *str)
{
	int	i;
	int	total;

	if (!str)
		total = write(1, "(null)", 6);
	else
	{
		total = 0;
		i = 0;
		while (str[i] != '\0')
		{
			total += write(1, &str[i], 1);
			i++;
		}
	}
	return (total);
}

int	ft_puthex(int caps, unsigned int num)
{
	char	*hex;
	char	n;
	int		total;

	total = 0;
	if (caps == 0)
		hex = "0123456789abcdef";
	if (caps == 1)
		hex = "0123456789ABCDEF";
	if (num >= 16)
		total += ft_puthex(caps, num / 16);
	n = hex[num % 16];
	total += write(1, &n, 1);
	return (total);
}

int	ft_putptr(int flag, unsigned long long num)
{
	char	*hex;
	char	n;
	int		total;

	total = 0;
	hex = "0123456789abcdef";
	if (num == 0 && flag == 0)
		total += write(1, "(nil)", 5);
	else
	{
		if (flag == 0)
			total += write(1, "0x", 2);
		if (num >= 16)
			total += ft_putptr(1, num / 16);
		n = hex[num % 16];
		total += write(1, &n, 1);
	}
	return (total);
}
