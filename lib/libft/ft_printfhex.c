/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:07:42 by khuynh            #+#    #+#             */
/*   Updated: 2022/09/03 18:16:55 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* %x et X: printer en hex min ou maj, return len
	1) compter la length avec / 16
	2) print en mode putnbr hex, >= 16 && <= 9
		careful on maj ou min selon X ou x
	3) reunir both, et la mettre dans ft_format */

int	ft_lenh(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_ptrh(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_ptrh(nb / 16, format);
		ft_ptrh(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + 48), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_phex(unsigned int nb, const char format)
{
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	ft_ptrh(nb, format);
	return (ft_lenh(nb));
}
