/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:53:23 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/06 19:51:39 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_f(va_list list, t_init *lst)
{
	t_float		init;
	long double nb;
	int			len;

	len = 0;
	if ((lst->flag & L_D) == L_D)
		nb = va_arg(list, long double);
	else
		nb = va_arg(list, double);
	init.f = nb;
	len = ft_exponent(&init.lst, lst->precision);
	return (len);
}
