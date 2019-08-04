/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:44:46 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/01 16:52:45 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_manage_width(t_format f, char *str)
{
	const int	str_len = ft_strlen(str);
	int			len;
	int			i;

	i = 0;
	len = 0;
	if (strchr(f.flag, '-'))
	{
		len += ft_str_nbr(str);
		while (i++ < f.width - str_len)
			len += ft_char_nbr(' ');
	}
	else
	{
		while (i++ < f.width - str_len)
			len += ft_char_nbr(' ');
		len += ft_str_nbr(str);
	}
	return (len);
}

int		ft_print_p(va_list list, t_format *f)
{
	unsigned long long int	nbr;
	int						len;
	char					*str;

	nbr = va_arg(list, unsigned long long int);
	str = ft_itoa_base(nbr, 16);
	str = ft_strjoin("0x", str);
	if (f->width > 0)
		len = ft_manage_width(*f, str);
	else
		len = ft_str_nbr(str);
	free(str);
	return (len);
}
