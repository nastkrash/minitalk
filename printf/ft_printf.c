/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:55:45 by anakrash          #+#    #+#             */
/*   Updated: 2024/10/20 21:02:40 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_param(const char *str, int i, va_list args)
{
	int	count;

	count = 0;
	if (str[i] == 's')
		count = ft_putstr(va_arg(args, char *));
	if (str[i] == 'c')
		count = ft_putchar(va_arg(args, int));
	if (str[i] == 'd' || str[i] == 'i')
		count = ft_putnbr(va_arg(args, int));
	if (str[i] == 'u')
		count = ft_putunnbr(va_arg(args, unsigned int));
	if (str[i] == 'X')
		count = ft_puthex(va_arg(args, unsigned int), true);
	if (str[i] == 'x')
		count = ft_puthex(va_arg(args, unsigned int), false);
	if (str[i] == 'p')
		count = ft_putpoint(va_arg(args, void *));
	if (str[i] == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	va_list			args;
	int				count;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
			count += ft_print_param(format, ++i, args);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
