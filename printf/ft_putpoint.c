/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:31:25 by anakrash          #+#    #+#             */
/*   Updated: 2024/10/20 17:35:09 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpoint(void *address)
{
	int	count;

	count = 0;
	if (!address)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	count += 2;
	count += ft_puthex((unsigned long)address, false);
	return (count);
}
