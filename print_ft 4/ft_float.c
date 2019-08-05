/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:37:41 by yelazrak          #+#    #+#             */
/*   Updated: 2019/08/02 19:38:10 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <stdio.h>

 char  *ft_reverse(char *str)
 {
     int i;
     int j;
     char tmp;

     i = 0;
     j = ft_strlen(str) - 1;
     while (i < j)
     {
         tmp = str[i];
         str[i] = str[j];
         str[j] = tmp;
         i++;
         j--;
     }
     return (str);
 }

char *ft_sum_2(char *a, char *b, int s_a, int s_b)
{
    int sum;
    int len;
    int i;
    int rest = 0;
    char *str;
    char aa;
    char bb;

    i = -1;
    len =  (s_a >=  s_b) ?  s_a :  s_b;
    str = ft_strnew(len + 1);
    while (++i < len)
    {
        aa = (i < s_a) ? a[i] : '0';
        bb = (i < s_b) ? b[i] : '0';
        sum = (aa - '0') + (bb - '0') + rest;
        str[i] = (sum % 10)  + '0';
        rest = sum / 10;
    }
    str[i]  = rest + '0';
      while (i > 0 && str[i] == '0')
            str[i] = '\0';   
    return (str);
}

char *ft_sum(char *a, char *b)
{
    int len;
    int s_a;
    int s_b;
    char *str;

    s_a  = ft_strlen(a);
    s_b = ft_strlen(b);
    len =  (s_a >=  s_b) ?  s_a :  s_b;
    str = ft_strnew(len + 1);
    a = ft_reverse(a);
    b = ft_reverse(b);
    str  = ft_sum_2(a,b,s_a, s_b);
    // ft_strdel(&a);
    // ft_strdel(&b);
    str = ft_reverse(str);
    return (str);
}

char *ft_strjoin_00(char *dst, int i)
{
    char *rst;
    char *str;

    str = ft_strdup(dst);
    while (i > 0)
    {
          rst = ft_strjoin(str, "0");
          free(str);
          str = rst;
        i--;
    }
     ft_strdel(&dst);
    return (str);
}

char *ft_produt(char *dst, char *s)
{
    char *ruslt;
    t_var   lst;
    char a ;

    lst.i  = ft_strlen(dst) + ft_strlen(s);
    if (!(ruslt = ft_strnew(lst.i)))
        return (NULL);
    ft_memset((char *)ruslt , '0',lst.i);
    lst.j = -1;
    lst.p = lst.i-1;
    lst.i = -1;
    s = ft_reverse(s);
    dst = ft_reverse(dst);
    while(s[++lst.j])
    {
        lst.i = -1;
        lst.k = lst.p--;
        lst.rest = 0;
        while (dst[++lst.i])
        {
            a = ruslt[lst.k];
            ruslt[lst.k] = (I(s[lst.j]) * I(dst[lst.i]) +  I(ruslt[lst.k]) + lst.rest) % 10  + '0';
            lst.rest = (I(s[lst.j]) * I(dst[lst.i]) +  I(a) + lst.rest) / 10;          
            lst.k--;         
        }
         ruslt[lst.k] = lst.rest + '0';
    }
    while (*ruslt == '0')
        (ruslt)++;
    // ft_strdel(&dst);
    // ft_strdel(&s);
    return (ruslt);
}


char *ft_power(char *str, long n)
{
    char *dst;
    char *tmp;
    char *tmp_2;

    if (n == 0)
        return (ft_strdup("1"));
    dst = ft_strdup(str);
    tmp_2 = ft_strdup(str);
    while (--n > 0)
    {
        tmp = dst;
        dst  = ft_produt(dst,tmp_2);
        //ft_strdel(&tmp);
    }
    return (dst);
}

// int main()
// {
//     char *s;

//   //s = ft_power(ft_strdup("123456789"), 123);
//  // s = ft_sum(ft_strdup("1111111101"),ft_strdup("9876543120"));
//   s = ft_produt(ft_strdup("464"), ft_strdup("1461"));
//     printf("%s\n", s);
// }