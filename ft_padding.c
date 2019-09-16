/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:08:04 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/16 14:54:55 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char *new;

	sign = *tmp;
	new = ft_strdup(str);
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
	ft_strdel(&new);
	return (str);
}

char			*ft_push_c(char *str, int i, char *c, int ps)
{
	char	*ptr;

	ptr = ft_strdup(str);
	while (i > 0)
	{
		if (ps == 1)
			ptr = ft_strjoin_free(ft_strdup(c), ptr);
		else if (ps == 0)
			ptr = ft_strjoin_free(ptr, ft_strdup(c));
		i--;
	}
	return (ptr);
}

static char		*ft_join_char(t_init *lst, char *str, int i)
{
	char		*tmp = NULL;
	char		*sign;

	if (ft_strstr(str, "nan"))
		 return ((ft_strdup(str)));
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
		str = ft_strjoin_free(ft_strdup(sign), str);
	ft_strdel(&sign);
	return (str);
}

static char		*ft_manage_precision(t_init *lst, char *str)
{
	const int	str_len = ft_strlen(str);
	int			i;
	char		*tmp;
	char		*tmp2;

	i = -1;
	tmp2 = NULL;
	if (lst->precision == 0 && *str == '0' && lst->specifier != 'f')
	{
		str = ft_strdup("");
		tmp2 = str;
	}
	if ((lst->specifier == 'x' || lst->specifier == 'X'
	|| lst->specifier == 'u') && str[0] == '\0')
		return (str);
	if (lst->precision > str_len && (lst->specifier != 'f'))
		if ((lst->flag & PLUS) == PLUS || str[0] == '-')
			i = lst->precision - str_len + 1;
		else
			i = lst->precision - str_len;
	else if (lst->precision < str_len && lst->specifier == 's')
		str = ft_safe(str, ft_strsub(str, 0, lst->precision));
	str = ft_join_char(lst, str, i);
	if (lst->specifier == 'o' && (lst->flag & HASH) == HASH && str[0] != '0')
	{
		tmp = str;
		str = ft_push_c(str, 1, "0", 1);
		ft_strdel(&tmp);
	}
	ft_strdel(&tmp2);
	return (str);
}

char			*ft_manage_width(t_init *lst, char *s)
{
	int			str_len;
	int			i;
	char		*str;
	char		*tmp;

	i = 0;
	str = ft_strdup(s);
	tmp = str;
	str = ft_manage_precision(lst, str);
	ft_strdel(&tmp);
	str_len = ft_strlen(str);
	if (lst->width > str_len)
	{
		if ((lst->flag & MINUS) == MINUS)
		{
			tmp = str;
			str = ft_push_c(str, lst->width - str_len, " ", 0);
			free(tmp);
		}
		else if ((lst->flag & ZERO) == ZERO && !ft_strstr(str, "inf")
		&& !ft_strstr(str, "nan"))
		{
			tmp = str;
			str = ft_join_char(lst, str, lst->width - str_len);
			free(tmp);
		}
		else
		{
			tmp = str;
			str = ft_push_c(str, lst->width - str_len, " ", 1);
			free(tmp);
		}
	}
	return (str);
}
