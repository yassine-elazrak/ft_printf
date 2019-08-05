/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:10:43 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/05 06:43:36 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(unsigned long long int value, int base)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		result = value % base;
		value /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long long int value, int base)
{
	char		*str;
	const char	*tab = "0123456789abcdef";
	int			len;
	int			result;

	result = 0;
	len = ft_count(value, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		exit(1);
	str[len--] = '\0';
	if (value == 0)
		return ("0");
	while (value > 0)
	{
		result = value % base;
		str[len--] = tab[result];
		value /= base;
	}
	return (str);
}
