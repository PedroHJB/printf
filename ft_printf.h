/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pede-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:37:29 by pede-jes          #+#    #+#             */
/*   Updated: 2025/01/01 21:07:19 by pede-jes         ###   ########.fr       */
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
int ft_putpointer(unsigned long long ptr);
int ft_putnbr(int n);

#endif
