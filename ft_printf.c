/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraile- <afraile-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:06:22 by afraile-          #+#    #+#             */
/*   Updated: 2025/05/01 20:07:15 by afraile-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(va_list argument, const char word);

int	ft_print_chr(int chr)
{
	write(1, &chr, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	argument;

	i = 0;
	size = 0;
	va_start(argument, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_select_format(argument, str[i + 1]);
			i++;
		}
		else
		{
			size += ft_print_chr(str[i]);
			i++;
		}
	}
	va_end(argument);
	return (size);
}

static int	ft_selectformat(va_list argument, const char word)
{
	int	size;

	size = 0;
	if (word == 'c')
		size += ft_print_chr(va_arg(argument, int));
	else if (word == 's')
		size += ft_print_str(va_arg(argument, char *));
	else if (word == 'p')
		size += ft_print_pointer(va_arg(argument, unsigned long long));
	else if (word == 'd' || word == 'i')
		size += ft_print_nbr(va_arg(argument, int));
	else if (word == 'u')
		size += ft_print_unsigned(va_arg(argument, unsigned int));
	else if (word == 'x' || word == 'X')
		size += ft_print_hexadecimal(va_arg(argument, unsigned int), word);
	else
		size += ft_print_chr(word);
	return (size);
}
