/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 04:18:22 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/06 19:34:38 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print(t_init *lst, unsigned long long int nbr)
{
	int		len;
	char	*str;

	len = 0;
	str = NULL;
	if (lst->specifier == 'o')
		str = ft_itoa_base(nbr, 8);
	if (lst->specifier == 'x' || lst->specifier == 'p')
		str = ft_itoa_base(nbr, 16);
	if (lst->specifier == 'X')
	{
		str = ft_itoa_base(nbr, 16);
		str = ft_str_toupper(str);
	}
	if (lst->specifier == 'u')
		str = ft_itoa_base(nbr, 10);
	str = ft_manage_width(lst, str);
	len += ft_str_nbr(str);
	return (len);
}

int				ft_print_base(va_list list, t_init *lst)
{
	unsigned long long int	nbr;
	int						len;

	len = 0;
	if ((lst->flag & LL) == LL || lst->specifier == 'p')
		nbr = va_arg(list, unsigned long long int);
	else if ((lst->flag & LONG) == LONG)
		nbr = va_arg(list, unsigned long int);
	else if ((lst->flag & HH) == HH)
		nbr = (unsigned char)va_arg(list, int);
	else if ((lst->flag & H) == H)
		nbr = (unsigned short)va_arg(list, int);
	else
		nbr = va_arg(list, unsigned int);
	len = ft_print(lst, nbr);
	return (len);
}
