/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraile- <afraile-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:01:42 by afraile-          #+#    #+#             */
/*   Updated: 2025/04/30 19:16:31 by afraile-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

int	ft_print_chr(int chr);
int	ft_printf(const char *str, ...);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hexadecimal(unsigned int num, const char word);
int	ft_print_pointer(unsigned long long ptr);

#endif
