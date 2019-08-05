/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:46:40 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/04 19:28:29 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <float.h>
#include <stdio.h>
#include <limits.h>


void		ft_print_bits(long long int i, int n)
{
	n--;
	while (n >= 0)
	{
		if ((i >> n) & 1)
			ft_putstr("1");
		else
		{
			ft_putstr("0");
		}
		n--;
	}
}

t_data		*ft_check(t_float *list)
{
	if ( list->lst.mantissa ==  0 && ((list->lst.exp & 32767) == 32767))
	{
		ft_putendl("inf");
		return (NULL);
	}
	else if(((list->lst.exp & 32767) == 32767) &&  list->lst.mantissa != 0)
	{
			ft_putendl("nan");
			return (NULL);
	}
	else if(list->lst.exp == 0 &&  list->lst.mantissa != 0)
		list->lst.exp = - 16382;
	else
		list->lst.exp = list->lst.exp -  16383;
	return (&list->lst);
}

void		ft_putstr_float(char *srcs,char  *dst, char *tmp,int prs)
{
	int a;

	a = ft_strlen(dst);
		ft_putstr(srcs);
	if(prs > 0)
		ft_putstr(".");
	ft_putstr(tmp);
	if (prs >= 63 && (( a) < prs))
	{
		prs -= 63;
		while (prs-- > 0)
			ft_putstr("0");
	}
	ft_strdel(&tmp);
	//ft_strdel(&dst);
	//ft_strdel(&srcs);
}

void		ft_randu(char *srcs,char  *dst,int prs)
{
	int i;
	char *str;
	char  *tmp;
	char   *tmp_3;
	char *tmp_2;
	int a;
	
	tmp = ft_strsub(dst,0,prs);
	tmp_2 = ft_strdup("1");
	a = ft_strlen(dst);
	if ((I(dst[prs ]) > 5) )
	{
		tmp_3 = tmp;
		tmp = ft_sum(tmp, tmp_2);
		ft_strdel(&tmp_3);
	}
	else if ((I(dst[prs ]) == 5))
	{
		i = prs + 1;
		while ((dst[i] == '0') && dst[i])
			i++;
			if( i < a)
			{
				tmp_3 = tmp;
				tmp = ft_sum(tmp, tmp_2);
				ft_strdel(&tmp_3);
			}
			else
			{
				if(I(dst[prs - 1]) % 2 != 0)
				{
					tmp_3 = tmp;
					tmp = ft_sum(tmp, tmp_2);
					ft_strdel(&tmp_3);
				}
			}
			
	}
	ft_putstr_float(srcs, dst, tmp, prs);
 }


void			ft_put_vurgile(char *str,int j,int prs)
{
	int i;
	char *tmp;
	char *tmp_2;

	i = ft_strlen(str) - 63;
	if (i >= 0 && j>=0)
	{
		tmp_2 = ft_strsub(str,0,i );
		ft_randu(tmp_2, &str[i], prs);
	}
	else
	{
		tmp_2 = ft_strdup("0");
		tmp = ft_strjoin_00(ft_strnew(0),abs(i + j));
		str = ft_strjoin(tmp, str);
		ft_strdel(&tmp);
		ft_randu(tmp_2, &str[0], prs);
	}
	ft_strdel(&tmp_2);
	//ft_strdel(&str);///////////////
	//tmp = ft_strjoin(tmp_2,&str[0]);
}


  void		ft_treat_float( t_data *lst, int prs)
  {
	int i;
	char *str;
	char  *tmp;
	char *tmp_2;
	char  *tmp_3;

	tmp = ft_strdup("5");
	tmp_2 = ft_strdup("2");
	i = 0; 
	str = ft_strdup("0");
	while (++i < 64) 
	{
        if((lst->mantissa >>  (63 - i)) & 1)
		{
			tmp_3 = str;
			str = ft_sum(str,ft_power(tmp, i));
			ft_strdel(&tmp_3);
		}			
		if (i < 63)
			str = ft_strjoin_00(str,1); 
    }
	if (lst->as & 1)
	{	
		tmp_3 = str;
		str = ft_strjoin("1",str);
		ft_strdel(&tmp_3);
	}	
	 tmp_3 = lst->exp < 0 ? tmp :tmp_2;
	ft_strdel(&tmp);
	tmp = str;
	str = ft_produt(str,ft_power(tmp_3,llabs(lst->exp)));
	ft_strdel(&tmp);
	ft_strdel(&tmp_2);
	ft_put_vurgile(str,lst->exp, prs);
  }

  void			ft_printf_f(long double fl,long long prsition)
  {
	    t_float *list;
		t_data   *tmp;
		char *str;

		if (!(list = (t_float *)malloc(sizeof(t_float))))
			return ;
		list->f = fl;
		if (!(tmp = ft_check(list)))
		{
			free(list);	
			return ;
		}
		
		ft_treat_float(tmp, prsition);
		free(list);
  }

  int	main()
  {
	    t_float list;
		t_data lst;
		
			long double t =(long double)INT_MAX;
			//;  ;//LDBL_MIN ;//
	printf("%.2147483647f\n",(double)t);//printf("\nprintf= = %.5lf\n",0.09999699);
	 ft_printf_f((long double)t,2147483647);
	  return 0;
  }
  