/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_persent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 21:48:44 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/04 14:47:39 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_check_specifier(char *format)
{
	int	i;

	i = -1;
	while (format[++i])
		if (ft_is_specifier(format[i]))
			return (1);
	return (0);
}

int		ft_print_persent(t_format *f, const char *format)
{
	char	*str;
	int		len;
	int		i;

	i = 1;
	str = ft_strdup(format);
	// printf("str => {%s}\n", str);
	while (*str)
		if (*str != '%')
			str++;
		else
			break ;
	while (str[i] != f->specifier)
		i++;
	if (str[i + 1] == f->specifier)
	{
		str[i] = 'c';
		str[i + 1] = '\0';
		// printf("%s\n", str);
		len = ft_printf(str, '%');
	}
	else
		len = ft_str_nbr("");
	return (len);
}
