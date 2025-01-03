/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <pede-jes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:45:26 by pede-jes          #+#    #+#             */
/*   Updated: 2025/01/03 18:25:12 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnnumber(unsigned int number)
{
	int		i;
	long	n;

	i = 0;
	n = number;
	if (n >= 10)
	{
		i += ft_putnumber(n / 10);
	}
	i += ft_putchar((n % 10) + '0');
	return (i);
}

int	ft_putstring(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstring("(null)"));
	while (*str)
	{
		i += write(1, str, 1);
		str++;
	}
	return (i);
}

int	ft_putpointer(unsigned long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	i += write(1, "0x", 2);
	i += ft_puthex(ptr);
	return (i);
}

int	ft_puthex(unsigned long n)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		i += ft_puthex(n / 16);
	i += write(1, &hex[n % 16], 1);
	return (i);
}

int	ft_puthexmax(unsigned long n)
{
	char	*hex;
	int		i;

	hex = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
		i += ft_puthexmax(n / 16);
	i += write(1, &hex[n % 16], 1);
	return (i);
}
