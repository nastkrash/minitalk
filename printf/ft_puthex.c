/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:31:17 by anakrash          #+#    #+#             */
/*   Updated: 2024/10/20 20:51:00 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	digit_nbr(unsigned long nbr)
{
	int	count;

	count = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned long nbr, bool is_upper)
{
	int		str_len;
	int		temp;
	char	*str;

	str_len = digit_nbr(nbr);
	temp = str_len;
	if (nbr == 0)
		return (ft_putstr("0"));
	str = malloc(str_len + 1);
	if (!str)
		return (0);
	while (nbr)
	{
		if (is_upper)
			str[--temp] = "0123456789ABCDEF"[nbr % 16];
		else
			str[--temp] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	str[str_len] = '\0';
	ft_putstr(str);
	free(str);
	return (str_len);
}

// int main()
// {
//     ft_putlowhex(23456789);
// }