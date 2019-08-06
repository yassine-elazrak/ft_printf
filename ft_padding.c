/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:08:04 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/06 19:58:19 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_push_c(char *str, int i, char *c, int ps)
{
	char	*tmp;
	t_free	*ptr;

	tmp = NULL;
	while (i > 0)
	{
		// ptr->tmp = str;
		// ptr = ptr->next;
		if (ps == 1)
			str = ft_strjoin(c, str);
		else if (ps == 0)
			str = ft_strjoin(str, c);
		i--;
		// ft_strdel(&tmp);
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

static char		*ft_join_char(t_init *lst, char *str, int i)
{
	char	*tmp;
	char	*sign;

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
		tmp = str;
		str = ft_strjoin(sign, str);
		// ft_strdel(&tmp);
	}
	ft_strdel(&sign);
	return (str);
}

static char		*ft_manage_precision(t_init *lst, char *str)
{
	const int	str_len = ft_strlen(str);
	int			i;

	i = -1;
	if (lst->precision == 0 && *str == '0')
	{
		// ft_strdel(&str);
		str = ft_strdup("");
	}
	if ((lst->specifier == 'x' || lst->specifier == 'X'
	|| lst->specifier == 'u') && str[0] == '\0')
		return (str);
	if (lst->precision > str_len)
	{
		if ((lst->flag & PLUS) == PLUS || str[0] == '-')
			i = lst->precision - str_len + 1;
		else
			i = lst->precision - str_len;
	}
	else if (lst->precision < str_len && lst->specifier == 's')
		str = ft_strsub(str, 0, lst->precision);
	str = ft_join_char(lst, str, i);
	if (lst->specifier == 'o' && (lst->flag & HASH) == HASH && str[0] != '0')
		str = ft_push_c(str, 1, "0", 1);
	return (str);
}

char			*ft_manage_width(t_init *lst, char *str)
{
	int			str_len;
	int			i;

	i = 0;
	str = ft_manage_precision(lst, str);
	str_len = ft_strlen(str);
	if (lst->width > str_len)
	{
		if ((lst->flag & MINUS) == MINUS)
			str = ft_push_c(str, lst->width - str_len, " ", 0);
		else if ((lst->flag & ZERO) == ZERO)
			str = ft_join_char(lst, str, lst->width - str_len);
		else
			str = ft_push_c(str, lst->width - str_len, " ", 1);
	}
	return (str);
}
