/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 22:04:15 by mobouzar          #+#    #+#             */
/*   Updated: 2019/07/23 18:37:11 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_manage_options(t_format f, char c)
{
	int	i;
	int	ret;

	ret = 0;
	if (ft_strchr(f.flag, '-'))
	{
		i = 0;
		ret += ft_char_nbr(c);
		while (i++ < f.width - 1)
			ret += ft_char_nbr(' ');
	}
	else
	{
		i = 0;
		while (i++ < f.width - 1)
			ret += ft_char_nbr(' ');
		ret += ft_char_nbr(c);
	}
	return (ret);
}

int		ft_print_c(va_list list, t_format *f)
{
	char	c;
	int		i;
	int		len;

	i = 0;
	c = (char)va_arg(list, int);
	len = c_manage_options(*f, c);
	return (len);
}

int		s_manage_options(t_format f, char *str)
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

char	*s_manage_precision(t_format f, char *str)
{
	char	*dst;
	int		i;

	i = -1;
	if (f.precision > 0)
		dst = ft_strsub((char *)str, 0, f.precision);
	else
		dst = ft_strsub((char *)str, 0, ft_strlen(str));
	return (dst);
}

int		ft_print_s(va_list list, t_format *f)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	str = va_arg(list, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	str = s_manage_precision(*f, str);
	len += s_manage_options(*f, str);
	return (len);
}
