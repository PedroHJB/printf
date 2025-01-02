/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:41:21 by pede-jes          #+#    #+#             */
/*   Updated: 2025/01/01 22:26:15 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *c = "abobora";
	int i = -2546;
	ft_printf("%d\n", i);
	printf("endereço :%d", i );
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
		i += ft_putpointer(va_arg(args,unsigned long));
	}
	else if(*string == 'd' || *string == 'i')
	{
		i += ft_putnumber(va_arg(args, int));
	}
	return (i);
}

int ft_putnumber(int n)
{
	int i;

	i = 0;

	if(n<0)
	{
		i += write(1,"-",1);
		n = n *-1;
	}

	if (n>=10)
	{
		i += ft_putnumber(n/10);
	}
	i += ft_putchar((n %10)+ '0');
	return i;
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

int ft_putpointer(unsigned long ptr)
{
	int i;

	i = 0;
	if (ptr	== 0)
		return (write(1,"(nil)",5));
	i += write(1,"0x",2);
	i += ft_puthex(ptr);
	return (i);	
}

int ft_puthex(unsigned long n)
{
	int i;
	char *hex;
		
	i = 0;
	hex = "0123456789abcdef";
	if(n >= 16)
		i += ft_puthex(n/16);
	i += write(1, &hex[n%16],1);
	return (i);
}

int ft_puthexmax(unsigned long n)
{
        int i;
	char *hex;

        i = 0;
        hex = "0123456789ABCDEF";
        if(n >= 16)
                i += ft_puthex(n/16);
        i += write(1, &hex[n%16],1);
        return (i);
}

