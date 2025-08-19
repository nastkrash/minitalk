/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:30:25 by anakrash          #+#    #+#             */
/*   Updated: 2024/10/20 17:34:12 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunnbr(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunnbr(n / 10);
		count += ft_putunnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		count++;
	}
	return (count);
}
