/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 08:27:31 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/05 21:38:15 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_width(t_init *lst, char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (lst->width > 0)
	{
		if (((lst->flag & MINUS) == MINUS))
			str = ft_push_c(str, lst->width - str_len, " ", 0);
		else
			str = ft_push_c(str, lst->width - str_len, " ", 1);
	}
	return (str);
}

int		ft_print_s(va_list list, t_init *lst)
{
	char	*str;
	int		str_len;
	int		len;

	len = 0;
	str = NULL;
	str_len = 0;
	str = va_arg(list, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	str_len = ft_strlen(str);
	if (lst->precision < str_len && lst->precision >= 0)
		str = ft_strsub(str, 0, lst->precision);
	str = ft_width(lst, str);
	len = ft_str_nbr(str);
	return (len);
}

int		ft_print_c(va_list list, t_init *lst)
{
	char	c;
	char	*str;
	int		len;

	len = 0;
	if (lst->specifier == 'c')
		c = (char)va_arg(list, int);
	else
		c = '%';
	str = ft_strnew(0);
	if (lst->width > 0)
		if (((lst->flag & MINUS) == MINUS))
		{
			str = ft_push_c(str, lst->width - 1, " ", 0);
			len += ft_char_nbr(c);
			len += ft_str_nbr(str);
		}
		else
		{
			str = ft_push_c(str, lst->width - 1, " ", 1);
			len += ft_str_nbr(str);
			len += ft_char_nbr(c);
		}
	else
		len += ft_char_nbr(c);
	return (len);
}

int		ft_print_persent(t_init *lst)
{
	int		len;
	char	*str;

	len = 0;
	if (lst->specifier == '\0')
		return (0);
	str = ft_strnew(2);
	str[0] = lst->specifier;
	str = ft_manage_width(lst, str);
	len += ft_str_nbr(str);
	ft_strdel(&str);
	return (len);
}
