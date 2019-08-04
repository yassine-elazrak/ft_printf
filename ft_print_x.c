/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:49:03 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/01 19:48:52 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*x_hash_manage(t_format f, char *str)
{
	int			i;
	int			precision;
	char		*dst;
	const int	str_len = ft_strlen(str);

	i = 2;
	precision = (f.precision * (f.precision > str_len));
	dst = ft_strnew(str_len + 2 + precision);
	dst = ft_strcpy(dst, "0x");
	while (i - 2 < (f.precision - (str_len)))
		dst[i++] = '0';
	dst = ft_strcat(dst, str);
	return (dst);
}

int		x_manage_options(t_format f, char *str)
{
	int const	str_len = ft_strlen(str);
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (ft_strchr(f.flag, '-'))
		if (f.width > str_len)
		{
			ret += ft_str_nbr(str);
			while (i++ < f.width - str_len)
				ret += ft_char_nbr(' ');
		}
		else
			ret += ft_str_nbr(str);
	else
	{
		if (ft_strchr(f.flag, '#') && !ft_strchr(f.flag, '-')
		&& str[0] && str[0] != '0')
		{
			if (f.width > str_len)
				while (i++ < f.width - str_len - 2)
					ret += ft_char_nbr(' ');
			if (f.specifier == 'X')
				ret += ft_str_nbr("0X");
			else
				ret += ft_str_nbr("0x");
			ret += ft_str_nbr(str);
		}
		else
		{
			if (f.width > str_len)
				while (i++ < f.width - str_len)
					ret += ft_char_nbr(' ');
			ret += ft_str_nbr(str);
		}
	}
	return (ret);
}

int		x_manage_zero(t_format f, char *str)
{
	const int	str_len = ft_strlen(str);
	int			len;
	int			i;
	int			j;

	i = 0;
	j = 0;
	len = 0;
	if (ft_strchr(f.flag, '0'))
	{
		if (f.precision > 0)
		{
			while (i++ < f.width - str_len)
				len += ft_char_nbr(' ');
			len += ft_str_nbr(str);
		}
		else
		{
			if (ft_strchr(f.flag, '#') && str[0] > '0')
			{
				if (f.specifier == 'X')
					len += ft_str_nbr("0X");
				else
					len += ft_str_nbr("0x");
				j = 2;
			}
			while (i++ < f.width - str_len - j)
				len += ft_char_nbr('0');
			len += ft_str_nbr(str);
		}
	}
	return (len);
}

char	*x_manage_precision(t_format f, char *str)
{
	char		*dst;
	int			i;
	const int	str_len = ft_strlen(str);

	i = 0;
	if (f.precision > 0)
		if (ft_strchr(f.flag, '#') && str[0] != '0')
			dst = x_hash_manage(f, str);
		else
		{
			dst = ft_strnew(str_len + (f.precision * (f.precision > str_len)));
			while (i < f.precision - str_len)
				dst[i++] = '0';
			dst = ft_strcat(dst, str);
		}
	else
	{
		dst = ft_strnew(str_len);
		if (ft_strchr(f.flag, '#') && str[0] != '0')
			if (ft_strchr(f.flag, '-'))
				dst = x_hash_manage(f, str);
			else
				dst = ft_strcpy(dst, str);
		else
			dst = ft_strcat(dst, str);
	}
	return (dst);
}

int		x_manage_format(t_format f, char *str)
{
	int len;

	len = 0;
	if (ft_strchr(f.flag, '0') && !ft_strchr(f.flag, '-') && f.precision != 0)
		len += x_manage_zero(f, str);
	else
		len += x_manage_options(f, str);
	return (len);
}

int		ft_print_x(va_list list, t_format *f)
{
	unsigned long long int	nbr;
	char					*str;
	int						len;
	int						i;

	i = 0;
	if (f->ll == 1)
		nbr = va_arg(list, unsigned long long int);
	else if (f->l == 1)
		nbr = va_arg(list, unsigned long int);
	else if (f->hh == 1)
		nbr = (unsigned char)va_arg(list, unsigned int);
	else if (f->h == 1)
		nbr = (unsigned short)va_arg(list, unsigned int);
	else
		nbr = va_arg(list, unsigned int);
	str = ft_itoa_base(nbr, 16);
	if (f->precision == 0 && str[0] == '0')
		str = ft_strdup("");
	else
	{
		if (f->specifier == 'X')
			str = ft_str_toupper(x_manage_precision(*f, str));
		else
			str = x_manage_precision(*f, str);
	}
	len = x_manage_format(*f, str);
	return (len);
}
