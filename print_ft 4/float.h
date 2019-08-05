/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:53:23 by yelazrak          #+#    #+#             */
/*   Updated: 2019/08/02 16:47:53 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FLOAT_H
# define FLOAT_H

# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_data
{
    unsigned long long  mantissa:63;
    unsigned long long           as:1;
    long long  exp:15;
    unsigned long long        signe:1;
}               t_data;

typedef union u_float
{
   long double   f;
    t_data      lst;
}               t_float;

typedef struct s_var
{
     int     i;
    int     j;
    int     k;
    int     rest;
    int     p; 
   
}               t_var;


#define I(x)      (x - '0')

char *ft_power(char *str, long n);
char *ft_sum(char *dst, char *srcs);
char *ft_strjoin_00(char *dst, int i);
char *ft_produt(char *dst, char *s);
char  *ft_reverse(char *str);

# endif


// t_data		*ft_check(t_data *lst)
// {
// 	if (lst->exp == 255 &&  lst->mantissa == 0)
// 	{
// 		ft_putendl("infiny");
// 		return (NULL);
// 	}
// 	else if(lst->exp == 255 &&  lst->mantissa != 0)
// 	{
// 			ft_putendl("NAN");
// 			return (NULL);
// 	}
// 	else if(lst->exp == 0 &&  lst->mantissa == 0)
// 	{
// 			ft_putendl("0");
// 			return (NULL);
// 	}
// 	else if(lst->exp == 0 &&  lst->mantissa != 0)
// 		lst->exp = -126;
// 	else
// 		lst->exp = lst->exp - 127;
// 	return (lst);
// }
