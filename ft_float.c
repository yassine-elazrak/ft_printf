/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:23:50 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/06 19:44:58 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mantissa(t_data *lst)
{
	t_var	var;
	int		i;

	i = 0;
	var.result = ft_strdup("0");
	while (++i < 64)
	{
		if ((lst->mantissa >> (63 - i)) & 1)
		{
			var.tmp = ft_power("5", i);
			var.result = ft_sum(var.result, var.tmp);
		}
		// printf("man = %s\n",var.result);
		if (i < 63)
			var.result = ft_strjoin(var.result, "0");
			//var.result = ft_strjoin_00(var.result, 1);
	}
	// printf("\nman = %s\n",var.result);
	return (var.result);
}

int		ft_putstr_float(char *src, char *dst, char *tmp, int prs)
{
	int		a;
	int		len;

	len = 0;
	a = ft_strlen(dst);
	len += ft_str_nbr(src);
	if (prs > 0)
		len += ft_char_nbr('.');
	len += ft_str_nbr(tmp);
	if (prs >= 63 && ((a) < prs))
	{
		prs -= 63;
		while (prs-- > 0)
			len += ft_char_nbr('0');
	}
	// ft_strdel(&tmp);
	return (len);
}

void	ft_check_randu(char **str, char **part_e, int prs)
{
	int		i;
	char	*tmp_2;
	char	*tmp;
	char	*dst;
	int		a;
	char	*tmp_3;

	dst = *str;
	tmp = *part_e;
	i = prs + i;
	a = ft_strlen(dst);
	while ((dst[i++] == '0') && dst[i])
		if (i < a)
		{
			tmp_3 = tmp;
			tmp = ft_sum(tmp, "1");
			// ft_strdel(&tmp_3);
		}
		else
		{
			if (I(dst[prs - 1]) % 2 != 0)
			{
				tmp_3 = tmp;
				tmp = ft_sum(tmp, "1");
				// ft_strdel(&tmp_3);
			}
		}
}

int		ft_randu(char *srcs, char *dst, int prs)
{
	char	*str;
	char	*tmp;
	char	*tmp_3;
	char	*tmp_2;
	int		len;

	tmp = ft_strsub(dst, 0, prs);
	if ((I(dst[prs]) > 5))
	{
		tmp_3 = tmp;
		tmp = ft_sum(tmp, "1");
		ft_strdel(&tmp_3);
	}
	else if ((I(dst[prs]) == 5))
		ft_check_randu(&dst, &tmp, prs);
	if (ft_strlen(tmp) > prs)
	{
		tmp_3 = ft_strsub(tmp, 0, 1);
		srcs = ft_sum(srcs, tmp_3);
		tmp = &tmp[1];
	}
	len = ft_putstr_float(srcs, dst, tmp, prs);
	return (len);
}

int		ft_get_vurgile(char *str, int exp, int prs)
{
	int		i;
	char	*tmp;
	char	*tmp_2;

	i = ft_strlen(str) - 63;
	if (i >= 0 && exp >= 0)
	{
		tmp_2 = ft_strsub(str, 0, i);
		i = ft_randu(tmp_2, &str[i], prs);
	}
	else
	{
		tmp_2 = ft_strdup("0");
		tmp = ft_strjoin_00(ft_strnew(0), ft_abs(i + exp));
		str = ft_strjoin(tmp, str);
		// ft_strdel(&tmp);
		i = ft_randu(tmp_2, &str[0], prs);
	}
	// ft_strdel(&tmp_2);
	return (i);
}

int		ft_exponent(t_data *lst, int prs)
{
	char	*str;
	char	*tmp;
	int		len;

	tmp = NULL;
	str = ft_mantissa(lst);
	lst->exp = lst->exp - 16383;
	if (lst->as & 1)
	{
		tmp = str;
		str = ft_strjoin("1", str);
		// ft_strdel(&tmp);
	}
	tmp = lst->exp < 0 ? "5" : "2";
	tmp = ft_power(tmp, ft_abs(lst->exp));
	str = ft_produit(str, tmp);
	// ft_strdel(&tmp);
	len = ft_get_vurgile(str, lst->exp, prs);
	return (len);
}
