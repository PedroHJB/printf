/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <pede-jes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:41:21 by pede-jes          #+#    #+#             */
/*   Updated: 2025/01/02 16:11:20 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			if (*string)
				i += ft_checksignal(string, ap);
		}
		else
		{
			i += ft_putchar(*string);
		}
		string++;
	}
	va_end(ap);
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_checksignal(const char *string, va_list args)
{
	int	i;

	i = 0;
	if (*string == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (*string == 's')
		i += ft_putstring(va_arg(args, char *));
	else if (*string == 'p')
		i += ft_putpointer(va_arg(args, unsigned long));
	else if (*string == 'd' || *string == 'i')
		i += ft_putnumber(va_arg(args, int));
	else if (*string == 'u')
		i += ft_putdecimal(va_arg(args, int));
	else if (*string == 'x')
		i += ft_puthex(va_arg(args, int));
	else if (*string == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_putdecimal(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		i += ft_putnumber(n / 10);
	}
	i += ft_putchar((n % 10) + '0');
	return (i);
}

int	ft_putnumber(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		i += ft_putnumber(n / 10);
	}
	i += ft_putchar((n % 10) + '0');
	return (i);
}

// int	main(void)
// {
// 	char	*c;
// 	int		i;

// 	c = "abobora";
// 	i = -2546;
// 	ft_printf("%s\n",c);
// 	printf("endereço :%s", c);
// 	return (0);
// }
