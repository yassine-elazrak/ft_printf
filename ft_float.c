/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:23:50 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/16 16:11:52 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_mantissa(t_data *lst)
{
	t_var	var;
	char *tmp;
	int		i;

	i = 0;
	var.result = ft_strdup("0");
	while (++i < 64)
	{
		if ((lst->mantissa >> (63 - i)) & 1)
		{
			tmp = var.result;
			var.tmp = ft_power("5", i);
			var.result = ft_sum(var.result, var.tmp);
			ft_strdel(&tmp);
			ft_strdel(&(var.tmp));
		}
		if (i < 63)
		{
			
			var.result = ft_strjoin_free((var.result), ft_strdup("0"));
			
		}
	}
	//ft_strdel(&var.tmp);
	//ft_strdel();
	return (var.result);
}

char		*ft_putstr_float(char *src, char *dst, char *tmp, int prs)
{
	int		a;
	int		len;

	len = 0;
	a = ft_strlen(dst);
	if (prs > 0 && !ft_strchr(src, '.'))
		src = ft_strjoin_free(src, ft_strdup("."));
	src = ft_strjoin_free(src, ft_strdup(tmp));
	if (prs >= 63 && ((a) < prs))
	{
		prs -= a;
		src = ft_strjoin_00(src, prs);
	}
	return (src);
}

void		ft_check_rounding(char **str, char **part_e, int prs)
{
	int		i;
	char	*str1;
	char	*tmp;
	char	*dst;
	char	*tmp_3;

	dst = *str;
	tmp = *part_e;
	i = prs + 1;
	while ((dst[i] == '0') && dst[i])
		i++;
	if (i < 63)
	{
		tmp_3 = *part_e;
		*part_e = ft_sum(*part_e, "1");
		ft_strdel(&tmp_3);
	}
	else
	{
		str1 = ft_strdup(*part_e);
		if (prs == 0)
		{
			if (I(str1[ft_strlen(str1) - 1]) % 2 != 0)
			{
				tmp_3 = *part_e;
				*part_e = ft_sum(str1, "1");
				ft_strdel(&tmp_3);

			}
		}
		else
		{
			if ((int)ft_strlen(*part_e) >= prs && I(*part_e[prs - 1]) % 2 != 0)
			{
				tmp_3 = *part_e;
				*part_e = ft_sum(*part_e, "1");
				ft_strdel(&tmp_3);

			}
		}
	}
}

char		*ft_rounding(char *srcs, char *dst, t_init	*lst, int prs)
{
	char	*tmp;
	char	*tmp_3;
	char    *tmp_2;

	tmp = ft_strsub(dst, 0, prs);
	if ((I(dst[prs]) > 5) && (int)ft_strlen(dst) >= prs)
	{
		tmp_3 = tmp;
		if (prs > 0)
			tmp = ft_sum(tmp, "1");
		else
		{
			ft_strdel(&tmp_3);
			tmp = ft_sum(srcs, "1");
			return (tmp);
		}
		ft_strdel(&tmp_3);
	}
	else if ((I(dst[prs]) == 5) && prs > 0)
		ft_check_rounding(&dst, &tmp, prs);

	else if ((I(dst[prs]) == 5) && prs == 0)
		ft_check_rounding(&dst, &srcs, prs);
	if ((int)ft_strlen(tmp) > prs && prs > 0)
	{
		tmp_3 = ft_strsub(tmp, 0, 1);
		tmp_2 = srcs;
		srcs = ft_sum(srcs, tmp_3);
		ft_strdel(&tmp_2);
		ft_strdel(&tmp_3);
		tmp_3 =  tmp;
		tmp = ft_strdup(&tmp[1]);
		ft_strdel(&tmp_3);
		
	}
	if ((lst->flag & HASH) == HASH)
		srcs = ft_strjoin_free(srcs, ft_strdup("."));

		tmp_3 =  tmp;
	tmp = ft_putstr_float(srcs, dst, tmp, prs);
		ft_strdel(&tmp_3);

	return (tmp);
}

char	*ft_get_vurgile(char *str, int exp, int prs, t_init	*lst)
{
	int		i;
	char	*tmp;
	char	*tmp_2;
	char	*ret;

	i = ft_strlen(str) - 63;
	if (i >= 0 && exp >= 0)
	{
		tmp_2 = ft_strsub(str, 0, i);
		tmp = str;

		str = ft_strdup(&str[i]);
		ft_strdel(&tmp);
		ret = ft_rounding(tmp_2, str, lst, prs);
	}
	else
	{
		if (ft_strchr(str, '-'))
		{
			tmp = str;
			tmp_2 = ft_strdup("-0");
			str = ft_strdup(&str[1]);
			ft_strdel(&tmp);
		}
		else
			tmp_2 = ft_strdup("0");
		tmp = ft_strjoin_00(ft_strnew(0), ft_abs(i + exp));
		str = ft_strjoin_free(tmp, str);///
		ret = ft_rounding(tmp_2, str, lst, prs);
	}
	ft_strdel(&str);
	return (ret);
}

char	*ft_exponent(t_data *list, int prs, t_init *lst)
{
	char	*str;
	char	*tmp;
	//char *tmp_2;

	tmp = NULL;
(void)lst;
(void)prs;
(void)list;
////	str = ft_strdup("0");
	str = ft_mantissa(list);
	if (list->exp != 0)
		list->exp = list->exp - 16383;
	if (list->as & 1)
	{
		//tmp = str;
		str = ft_strjoin_free(ft_strdup("1"), (str));
	}
	tmp = list->exp < 0 ? "5" : "2";
	tmp = ft_power(tmp, ft_abs(list->exp));
	//tmp_2 = str;
	str = ft_safe(str, ft_produit(str, tmp));
//	ft_strdel(&tmp_2);
	ft_strdel(&tmp);
	if (list->sign & 1)
		str = ft_strjoin_free(ft_strdup("-"), str);
	str = ft_get_vurgile(str, list->exp, prs, lst);
	
	return (str);
}
