/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:47:29 by mobouzar          #+#    #+#             */
/*   Updated: 2019/07/30 19:00:17 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_manage_mines(t_format f, char *str)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	if (ft_strchr(f.flag, ' '))
	{
		ret += ft_char_nbr(' ');
		ret += ft_str_nbr(str);
		while (i++ < f.width - (int)ft_strlen(str))
			ret += ft_char_nbr(' ');
	}
	else if (f.width > (int)ft_strlen(str))
	{
		ret += ft_str_nbr(str);
		while (i++ < f.width - (int)ft_strlen(str))
			ret += ft_char_nbr(' ');
	}
	else
		ret += ft_str_nbr(str);
	return (ret);
}

char	*ft_manage_plus(t_format f, char *str)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (f.width > (int)ft_strlen(str) + 1)
	{
		//free(dst);
		if (str[0] == '-')
		{
			dst = ft_strnew(f.width - (int)ft_strlen(str));
			while (i < f.width - (int)ft_strlen(str))
				dst[i++] = ' ';
			dst = ft_strjoin(dst, str);
		}
		else if (ft_strchr(f.flag, '-') && ft_strchr(f.flag, '+'))
		{
			dst = ft_strnew(f.width);
			dst[i] = '+';
			dst = ft_strcat(dst, str);
			i = ft_strlen(dst);
			while (i < f.width)
				dst[i++] = ' ';
		}
		else
		{
			dst = ft_strnew(ft_strlen(str));
			while (i < f.width - (int)ft_strlen(str) - 1)
				dst[i++] = ' ';
			dst[i] = '+';
			dst = ft_strjoin(dst, str);
		}
	}
	else
	{
		if (str[0] == '-')
			dst = ft_strdup(str);
		else
			dst = ft_strjoin("+", str);
	}
	return (dst);
}

int		ft_manage_space(t_format f, char *str)
{
	char	ret;
	int		i;

	i = 0;
	if (f.width > (int)ft_strlen(str))
	{
		while (i++ < f.width - (int)ft_strlen(str))
			ret += ft_char_nbr(' ');
		ret += ft_str_nbr(str);
	}
	else
	{
		if (f.precision <= 0)
			ret += ft_char_nbr(' ');
		ret += ft_str_nbr(str);
	}
	return (ret);
}

int		d_manage_options(t_format f, char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (f.precision == 0 && str[0] == '0')
		str = ft_strdup("");
	if (ft_strchr(f.flag, '-') && !ft_strchr(f.flag, '+') &&
	!ft_strchr(f.flag, ' '))
		ret += ft_manage_mines(f, str);
	else if (ft_strchr(f.flag, '+'))
	{
		str = ft_manage_plus(f, str);
		ret += ft_str_nbr(str);
	//	free(str);
	}
	else if (ft_strchr(f.flag, '+') && ft_strchr(f.flag, '-'))
	{
		str = ft_manage_plus(f, str);
		ret += ft_str_nbr(str);
	//	free(str);
	}
	else if (ft_strchr(f.flag, ' ') && ft_strchr(f.flag, '+'))
	{
		ret += ft_manage_mines(f, str);
	}
	else if (ft_strchr(f.flag, ' ') && ft_atoi(str) >= 0 &&
	!ft_strchr(f.flag, '+'))
		ret += ft_manage_space(f, str);
	else
	{
		if (f.width > (int)ft_strlen(str))
			while (i++ < f.width - (int)ft_strlen(str))
				ret += ft_char_nbr(' ');
		ret += ft_str_nbr(str);
	}
	// if (f.precision == 0 && str[0] == '0')
	// 	free(str);
	return (ret);
}

/* *********** function that manage flag 0 *************** */

char	*t_manage_zero(t_format f, char *str)
{
	char	*dst;
	int		i;

	i = 0;
	if (f.precision == 0 && str[0] == '0')
		str = ft_strdup("");
	dst = ft_strnew(ft_strlen(str));
	if (f.width > (int)ft_strlen(str))
	{
		if (str[0] == '-')
		{
		//	free(dst);
			dst = ft_strnew(f.width - (int)ft_strlen(str) + 1);
			dst[0] = '-';
			while (++i < f.width - (int)ft_strlen(str) + 1)
				dst[i] = '0';
			dst = ft_strjoin(dst, ft_strsub(str, 1, ft_strlen(str) - 1));
		}
		else
		{
		//	free(dst);
			dst = ft_strnew(f.width - (int)ft_strlen(str));
			while (i < f.width - (int)ft_strlen(str))
				dst[i++] = '0';
			dst = ft_strjoin(dst, str);
		}
	}
	else
	{
		if (ft_strchr(f.flag, '+') && ft_strchr(f.flag, '-') &&
		ft_strchr(f.flag, ' '))
			dst = ft_strjoin("+", str);
		else if (ft_strchr(f.flag, ' '))
			dst = ft_strjoin(" ", str);
		else if (ft_strchr(f.flag, '+'))
			dst = ft_strjoin("+", str);
		else
			dst = ft_strdup(str);
	}
	// if (f.precision == 0 && str[0] == '0')
	// 	free(str);
	return (dst);
}

/* *********** function that manage precision  *************** */

char	*manage_sign(t_format f, char *str, char *dst)
{
	int		i;

	i = 0;
	if (ft_strchr(f.flag, ' '))
	{
		dst[0] = ' ';
		while (i <= f.precision - (int)ft_strlen(str) - 1)
			dst[++i] = '0';
		dst = ft_strjoin(dst, str);
	}
	else
	{
		while (i <= f.precision - (int)ft_strlen(str) - 1)
			dst[i++] = '0';
		dst = ft_strjoin(dst, str);
	}
	return (dst);
}

char	*ft_manage_precision(t_format f, char *str)
{
	char	*dst;
	int		i;

	i = 0;
	if (f.precision <= (int)ft_strlen(str))
		dst = ft_strdup(str);
	else
	{
		dst = ft_strnew((int)ft_strlen(str));
		if (str[0] == '-')
		{
			dst[0] = '-';
			while (i <= f.precision - (int)ft_strlen(str))
				dst[++i] = '0';
			dst = ft_strjoin(dst, ft_strsub(str, 1, ft_strlen(str) - 1));
		}
		else
			dst = manage_sign(f, str, dst);
	}
	return (dst);
}

/* *********** function that manage format  *************** */

int		ft_manage_flags(t_format f, char *str)
{
	char	*dst;
	int		len;

	len = 0;
	if (ft_strchr(f.flag, '0') && f.precision < 0)
	{
		dst = t_manage_zero(f, str);
		len += ft_str_nbr(dst);
	}
	else if (ft_strchr(f.flag, '0') && f.precision >= 0)
		len += d_manage_options(f, str);
	else
		len += d_manage_options(f, str);
	return (len);
}

int		ft_print_d(va_list list, t_format *f)
{
	long long int	nbr;
	char			*str;
	int				len;
	int				i;

	i = 0;
	len = 0;
	if (f->ll == 1)
		nbr = va_arg(list, long long int);
	else if (f->l == 1)
		nbr = va_arg(list, long int);
	else if (f->hh == 1)
		nbr = (char)va_arg(list, int);
	else if (f->h == 1)
		nbr = (short)va_arg(list, int);
	else
		nbr = va_arg(list, int);
	str = ft_itoa(nbr);
	if (f->precision > 0)
		str = ft_manage_precision(*f, str);
	len += ft_manage_flags(*f, str);
	//free(str);
	return (len);
}
