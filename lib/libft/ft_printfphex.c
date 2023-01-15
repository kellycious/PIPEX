/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfphex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:56 by khuynh            #+#    #+#             */
/*   Updated: 2022/09/03 18:17:06 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  %p: print pointeur en hexa, decompose en 3 fonctions
		1) longueur 2)print en hexa 3) 2+1 et gerer les cas speciaux
		uintptr_t == 
*/

int	ft_lenhex(uintptr_t	nb)
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

void	ft_ptrhex(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_ptrhex(nb / 16);
		ft_ptrhex(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + 48), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

int	ft_pptrhex(unsigned long long nb)
{
	int	ptr;

	ptr = 0;
	if (nb == 0)
		return (write(1, "(nil)", 5));
	ptr += write(1, "0x", 2);
	ft_ptrhex(nb);
	ptr += ft_lenhex(nb);
	return (ptr);
}
