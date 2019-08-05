/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:46:40 by mobouzar          #+#    #+#             */
/*   Updated: 2019/07/30 19:15:07 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_char_nbr(char c)
{
	ft_putchar(c);
	return (1);
}

int		ft_str_nbr(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	return (i);
}

int		ft_manage_format(va_list list, t_format *f)
{
	int	ret;

	ret = 0;
	if (f->specifier == 'c')
		ret += ft_print_c(list, f);
	if (f->specifier == 's')
		ret += ft_print_s(list, f);
	if (f->specifier == 'd' || f->specifier == 'i')
		ret += ft_print_d(list, f);
	return (ret);
}

int		ft_print_format(va_list list, const char *format, t_format *f)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ret += ft_char_nbr(format[i]);
		else
		{
			j = ft_getformat(f, format + i);
			ret += ft_manage_format(list, f);
			i += j;
		}
		i++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	t_format	f;
	int			ret;

	va_start(list, format);
	ret = ft_print_format(list, format, &f);
	va_end(list);
	return (ret);
}
