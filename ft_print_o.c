/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 15:01:50 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/02 21:42:26 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		o_manage_options(t_format f, char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (ft_strchr(f.flag, '-'))
		if (f.width > (int)ft_strlen(str))
		{
			ret += ft_str_nbr(str);
			while (i++ < f.width - (int)ft_strlen(str))
				ret += ft_char_nbr(' ');
		}
		else
			ret += ft_str_nbr(str);
	else
	{
		if (f.width > (int)ft_strlen(str))
			while (i++ < f.width - (int)ft_strlen(str))
				ret += ft_char_nbr(' ');
		ret += ft_str_nbr(str);
	}
	return (ret);
}

int		o_manage_zero(t_format f, char *str)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (ft_strchr(f.flag, '0'))
	{
		if (f.precision > 0)
		{
			while (i++ < f.width - (int)ft_strlen(str))
				len += ft_char_nbr(' ');
			len += ft_str_nbr(str);
		}
		else
		{
			while (i++ < f.width - (int)ft_strlen(str))
				len += ft_char_nbr('0');
			len += ft_str_nbr(str);
		}
	}
	return (len);
}

char	*o_hash_manage(t_format f, char *dst, char *str)
{
	int	i;

	i = 0;
	dst[0] = '0';
	while (++i < f.precision - (int)ft_strlen(str))
		dst[i] = '0';
	dst = ft_strcat(dst, str);
	return (dst);
}

char	*o_manage_precision(t_format f, char *str)
{
	char	*dst;
	int		i;

	i = 0;
	dst = ft_strnew(ft_strlen(str));
	if (f.precision > (int)ft_strlen(str))
	{
		free(dst);
		dst = ft_strnew(f.precision);
		if (ft_strchr(f.flag, '#') && str[0] != '0')
			o_hash_manage(f, dst, str);
		else
		{
			while (i < f.precision - (int)ft_strlen(str))
				dst[i++] = '0';
			dst = ft_strcat(dst, str);
		}
	}
	else
	{
		if (ft_strchr(f.flag, '#') && str[0] != '0')
			dst[0] = '0';
		dst = ft_strcat(dst, str);
	}
	return (dst);
}

int		o_manage_format(t_format f, char *str)
{
	int len;

	len = 0;
	if (ft_strchr(f.flag, '0') && !ft_strchr(f.flag, '-') && f.precision != 0)
	{
		len += o_manage_zero(f, str);
	}
	else
	{
		len += o_manage_options(f, str);
	}
	return (len);
}

int		ft_print_o(va_list list, t_format *f)
{
	unsigned long long int	nbr;
	char					*str;
	int						len;
	int						i;

	i = 0;
	len = 0;
	if (f->ll == 1)
		nbr = va_arg(list, unsigned long long int);
	else if (f->l == 1)
		nbr = va_arg(list, unsigned long int);
	else if (f->hh == 1)
		nbr = (unsigned char)va_arg(list, int);
	else if (f->h == 1)
		nbr = (unsigned short)va_arg(list, int);
	else
		nbr = va_arg(list, unsigned int);
	str = ft_itoa_base(nbr, 8);
	if (f->precision == 0 && !ft_strchr(f->flag, '#') && str[0] == '0')
		str = ft_strdup("");
	else
		str = o_manage_precision(*f, str);
	len += o_manage_format(*f, str);
	free(str);
	return (len);
}
