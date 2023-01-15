/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:26:51 by khuynh            #+#    #+#             */
/*   Updated: 2022/09/03 18:16:35 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* gerer args, retourne length of the input
   regarder si le proto est respecté i.e "%..."
   ensuite check quel format c'est cspdiuxX%, recupe les lenghts
   si c'est pas le cas, print direct ce qui est ecrit
   ne pas oublier de fermer la liste variadiques arg */

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;
	int		i;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i + 1] && str[i] == '%')
		{
			len = len + ft_format(args, str[i + 1]);
			i++;
		}
		else
			len += ft_pchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/* plusieurs boucles "if", si format == cspdiuxX% treat selon le format
	+ store leur len pour return */

int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = len + ft_pchar((char)va_arg(args, int));
	else if (format == 's')
		len = len + ft_pstr((char *)va_arg(args, char *));
	else if (format == 'p')
		len = len + ft_pptrhex(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		len = len + ft_pnb((int)va_arg(args, int));
	else if (format == 'u')
		len = len + ft_punsignednb(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len = len + ft_phex(va_arg(args, int), format);
	else if (format == '%')
		len = len + ft_pourcent();
	return (len);
}

// %c: imprimer 1 char et retourner 1
int	ft_pchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// %s: imprimer une chaine de carac, retourner length

int	ft_pstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		i++;
	}
	ft_putstr_fd(str, 1);
	return (i);
}

// %%: print juste 1 % et return (1)

int	ft_pourcent(void)
{
	write (1, "%", 1);
	return (1);
}

/*
#include <stdio.h>
int main ()
{
    ft_printf("coucou je mapelle %s gros %d\n", "hello", 19);
    printf("%d\n", 19);
}*/
