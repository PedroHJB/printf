/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:41:21 by pede-jes          #+#    #+#             */
/*   Updated: 2025/01/01 21:12:22 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *c = "abobora";
	ft_printf("%p",c);
	printf("endereço :%s",c);
	return(0);
}

int ft_printf(const char *string, ...)
{
	va_list ap;
	int i;
	
	i = 0;
	va_start(ap,string);
	while(*string)
	{
		if(*string == '%')
		{
			string++;
			if(*string)
				i += ft_checksignal(string,ap);
		}
		else
		{
			i += ft_putchar(*string);
		}
		string ++;
	}

	va_end(ap);
	return(0);
}

int ft_putchar(char c)
{
	write(1,&c,1);
	return (1);
}

int ft_checksignal(const char *string, va_list args)
{
	int i;

	i = 0;

	if(*string == 'c')
	{
		i += ft_putchar(va_arg(args,int));
	}
	else if(*string == 's')
	{	
		i+= ft_putstring(va_arg(args,char *));
	}
	else if(*string == 'p')
	{
		i += ft_putpointer((unsigned long long)va_arg(args,char *));
	}
	return (i);
}

int ft_putstring(char *str)
{
	int i;
	
	i = 0;

	while(*str)
	{
		i += write(1,str,1);
		str++;
	}
	return (i);

}

int ft_putpointer(unsigned long long ptr)
{
	int i;

	i = 0;
	i += write(1,&ptr,15); 
	return (i);
}

int ft_putnbr(int number)
{
	int i;
	char nb[20];

	i = 0;
	while(number <= 10)
		nb[i++] = '0' + number/10;
	nb[++i] = '0' + number;
	ft_putstring(nb);
	return (i);
}
