/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:51:14 by mobouzar          #+#    #+#             */
/*   Updated: 2019/07/26 21:34:17 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct	s_format
{
	char		specifier;
	int			width;
	int			precision;
	char		flag[5];
	int			l;
	int			ll;
	int			h;
	int			hh;
}				t_format;

/* ************** initialise options ************* */
void			ft_init(t_format *f);
int				ft_flag(t_format *f, const char *format);
int				ft_width(t_format *f, const char *format, int i);
int				ft_precision(t_format *f, const char *format, int i);
void			ft_modifier(t_format *f, const char *format, int i);

/* ************** manage format ***************** */
int				ft_is_specifier(char c);
int				ft_getformat(t_format *f, const char *format);
int				ft_manage_format(va_list list, t_format *f);
int				ft_count_format(char c);

/* ************* print functions **************** */
int				ft_char_nbr(char c);
int				ft_str_nbr(char *s);

/* ************* manage specifiers *************** */
int				ft_print_c(va_list list, t_format *f);
int				ft_print_s(va_list list, t_format *f);
int				ft_print_d(va_list list, t_format *f);

/* ************** ft_printf ********************* */
int				ft_printf(const char *format, ...);

#endif
