/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 09:18:54 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/15 08:48:55 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_strnew_00(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		exit(1);
	while (size--)
	{
		*(str++) = '0';
		i++;
	}
	*str = '\0';
	return (str - i);
}

char	*ft_strjoin_00(char *dst, int i)
{
	char *str;

	str = ft_strdup(dst);
	while (i > 0)
	{
		str = ft_strjoin_free(str, ft_strdup("0"));
		i--;
	}
	ft_strdel(&dst);
	return (str);
}

char	*ft_sum(char *a, char *b)
{
	t_var	var;
	int		i;

	i = -1;
	var.rest = 0;
	var.s_a = ft_strlen(a) - 1;
	var.s_b = ft_strlen(b) - 1;
	var.len = (var.s_a > var.s_b) ? var.s_a + 1 : var.s_b + 1;
	var.result = ft_strnew_00(var.len + 1);
	var.csnt = var.len;
	while (++i < var.csnt)
	{
		var.aa = (-1 < var.s_a) ? a[var.s_a--] : '0';
		var.bb = (-1 < var.s_b) ? b[var.s_b--] : '0';
		var.result[var.len] = K(((I(var.aa) + I(var.bb) + var.rest) % 10));
		var.len--;
		var.rest = (I(var.aa) + I(var.bb) + var.rest) / 10;
	}
	var.result[var.len] = K(var.rest);
	var.tmp = var.result;
	if (*(var.result) == '0')
		(var.result)++;
	var.result = ft_strdup(var.result);
	ft_strdel(&var.tmp);
	return (var.result);
}

char	*ft_produit(char *a, char *b)
{
	t_var	var;
	int		prd;

	var.s_a = ft_strlen(a);
	var.s_b = ft_strlen(b);
	var.len = var.s_a + var.s_b;
	var.result = ft_strnew_00(var.len);
	while (--var.s_b >= 0)
	{
		var.i = var.s_a;
		var.k = --var.len;
		var.rest = 0;
		while (--var.i >= 0)
		{
			var.aa = var.result[var.k];
			prd = I(b[var.s_b]) * I(a[var.i]);
			var.result[var.k] = K((prd + I(var.result[var.k]) + var.rest) % 10);
			var.rest = (prd + I(var.aa) + var.rest) / 10;
			var.k--;
		}
		var.result[var.k] = K(var.rest);
	}
	var.tmp = var.result;
	while (*(var.result) == '0' && *(var.result + 1) != '\0')
		(var.result)++;
	var.result = ft_strdup(var.result);
	ft_strdel(&var.tmp);
	return (var.result);
}

char	*ft_power(char *str, long n)
{
	char	*dst;
	char	*tmp;

	tmp = NULL;
	if (n == 0)
		return (ft_strdup("1"));
	dst = ft_strdup(str);
	while (--n > 0)
	{
		tmp = dst;
		dst = ft_produit(dst, str);
		 ft_strdel(&tmp);
	}
	return (dst);
}

// int 	main()
// {
// 	char *tmp;
// 	int n;

// 	n = 999;
// while (n--)
// {
// 	tmp = ft_power("12",2);

// 	ft_strdel(&tmp);
// }


// 	return 0;
// }
