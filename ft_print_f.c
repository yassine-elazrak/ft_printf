/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:53:23 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/15 20:26:14 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*indefined_form(long double nbr)
{
	if (nbr == (1.0 / 0.0))
		return (ft_strdup("inf"));
	if (nbr == (-1.0 / 0.0))
		return (ft_strdup("-inf"));
	if (nbr != nbr)
		return (ft_strdup("nan"));
	return (ft_strdup(""));
}

int		ft_print_f(va_list list, t_init *lst)
{
	t_float		init;
	char		*str = NULL;
	long double nb;
	double		k;
	int			len;
	//char        *tmp;
	int h = 0;

	len = 0;

	init.f = 0.0;
	init.list.exp = 0.0;
	init.list.mantissa = 0.0;
	if ((lst->flag & L_D) == L_D)
	{
		nb = va_arg(list, long double);
		init.f = (long double)nb;
	}
	else
	{
		k = va_arg(list, double);
		init.f = k;
	}
	if ((init.f == 1.0 / 0.0) || (init.f == -1.0 / 0.0) || (init.f != init.f))
	{
		str = indefined_form(init.f);
		h  = 9;
	}
	else
	{
		str = ft_exponent(&init.list, lst->precision, lst);
	}
	
	///str = ft_safe(str,ft_strdup(str));
	 str = ft_safe(str,ft_manage_width(lst, str));

	len += ft_str_nbr(str);
	 	ft_strdel(&str);

	return (len);
}
