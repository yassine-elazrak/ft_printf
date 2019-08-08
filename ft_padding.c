/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:08:04 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/08 21:19:28 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_push_c(char *str, int i, char *c, int ps)
{
	char	*tmp;

	tmp = ft_strdup(str);
	while (i > 0)
	{
		if (ps == 1)
			tmp = ft_strjoin_free(ft_strdup(c), tmp);
		else if (ps == 0)
			tmp = ft_strjoin_free(tmp, ft_strdup(c));
		i--;
	}
	//ft_strdel(&str);
	return (tmp);
}

static char		*ft_prefix(t_init *lst, char *str, char *sign)
{
	if (str[0] == '0' && str[1] == 'x')
	{
		sign[0] = '0';
		sign[1] = 'x';
		str += 2;
	}
	if (str[0] == '0' && str[1] == 'X')
	{
		sign[0] = '0';
		sign[1] = 'X';
		str += 2;
	}
	if ((str[0] != '0' && ((lst->flag & HASH) == HASH)
	&& lst->specifier == 'x') || lst->specifier == 'p')
	{
		sign[0] = '0';
		sign[1] = 'x';
	}
	if (str[0] != '0' && ((lst->flag & HASH) == HASH) && lst->specifier == 'X')
	{
		sign[0] = '0';
		sign[1] = 'X';
	}
	return (str);
}

static char		*ft_check(t_init *lst, char *str, char **tmp)
{
	char *sign;

	sign = *tmp;
	if (*str == '-')
	{
		*sign = '-';
		str++;
	}
	if (*str == '+')
	{
		*sign = '+';
		str++;
	}
	if (*str == ' ')
	{
		*sign = ' ';
		str++;
	}
	str = ft_prefix(lst, str, sign);
	return (str);
}

static char		*ft_join_char(t_init *lst, char *str, int i)
{
	const int	str_len = ft_strlen(str);
	char		*tmp;
	char		*sign;

	if (ft_strstr(str, "nan"))
		return (str);
	sign = ft_strnew(3);
	tmp = str;
	str = ft_check(lst, str, &sign);
	if ((lst->flag & PLUS) == PLUS && tmp[0] != '-')
		*sign = '+';
	else if ((lst->flag & SPACE) == SPACE && tmp[0] != '-' && tmp[0] != '+')
		*sign = ' ';
	if (((lst->flag & PLUS) == PLUS) && tmp[0] != '-' && tmp[0] != '+')
		i--;
	str = ft_push_c(str, i, "0", 1);
	if (*sign != '\0')
	{
		str = ft_strjoin_free(sign, str);
		// ft_strdel(&tmp);
	}
	// ft_strdel(&sign);
	return (str);
}

static char		*ft_manage_precision(t_init *lst, char *str)
{
	const int	str_len = ft_strlen(str);
	int			i;

	i = -1;
	if (lst->precision == 0 && *str == '0' && lst->specifier != 'f')
	{
		str = ft_strdup("");
	}
	if ((lst->specifier == 'x' || lst->specifier == 'X'
	|| lst->specifier == 'u') && str[0] == '\0')
		return (str);
	if (lst->precision > str_len && (lst->specifier != 'f'))
	{
		if ((lst->flag & PLUS) == PLUS || str[0] == '-')
			i = lst->precision - str_len + 1;
		else
			i = lst->precision - str_len;
	}
	else if (lst->precision < str_len && lst->specifier == 's')
		str = ft_strsub(str, 0, lst->precision);
	char *t;
	t = str;
	str = ft_join_char(lst, str, i);
	//free(t);
	if (lst->specifier == 'o' && (lst->flag & HASH) == HASH && str[0] != '0')
		str = ft_push_c(str, 1, "0", 1);
	return (str);
}

char			*ft_manage_width(t_init *lst, char *s)
{
	int			str_len;
	int			i;
	char *str;

	str = ft_strdup(s);

	i = 0;
	str = ft_manage_precision(lst, str);
	str_len = ft_strlen(str);
	if (lst->width > str_len)
	{
		if ((lst->flag & MINUS) == MINUS)
			str = ft_push_c(str, lst->width - str_len, " ", 0);
		else if ((lst->flag & ZERO) == ZERO && !ft_strstr(str, "inf")
		&& !ft_strstr(str, "nan"))
			str = ft_safe(str, ft_join_char(lst, str, lst->width - str_len));
		else
			str = ft_push_c(str, lst->width - str_len, " ", 1);
	}
	return (str);
}
