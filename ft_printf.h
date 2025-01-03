/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <pede-jes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:37:29 by pede-jes          #+#    #+#             */
/*   Updated: 2025/01/03 17:02:45 by pede-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int ft_printf(const char *string,...);
int ft_putchar(char c);
int ft_checksignal(const char *string, va_list args);
int ft_putstring(char *c);
int ft_putpointer(unsigned long ptr);
int ft_putnbr(unsigned long long n);
int ft_puthex(unsigned long n);
int ft_puthexmax(unsigned long n);
int ft_putnumber(int n);
int ft_putdecimal(unsigned int n);

#endif
