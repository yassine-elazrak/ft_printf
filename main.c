/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:34:10 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/08 19:53:12 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int	main()
{
	int	i;
	int j;

	// i = ft_printf("|%.o|%-.o|%#.o|%0.o|\n", 0U, 0U, 0U, 0U);
	// j =    printf("|%.o|%-.o|%#.o|%0.o|\n", 0U, 0U, 0U, 0U);
	// i =    ft_printf("|%-#23.5llX|%-023.5llX|%#023.5llX|%-#023.5llX|\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	// j =    printf("|%-#23.5llX|%-023.5llX|%#023.5llX|%-#023.5llX|\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	//  i =    ft_printf("|%f|\n", 0.);
// i =   ft_printf("|%f|%-f|%+f|% f|%#f|%0f|\n", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN);
			 i =ft_printf("%.2147483649f|%2147483649f|\n", 1.0, 1.0);
			j = printf("%.2147483649f|%2147483649f|\n", 1.0, 1.0);
	j =   // printf("%+8.14Lf|%+ 8.14Lf|%+-8.14Lf|%+#8.14Lf|%+08.14Lf|%+ -#08.14Lf", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L);
	// j =       printf("|%f|%-f|%+f|% f|%#f|%0f|\n", 0., 0., 0., 0., 0., 0.);
	// j =    	  printf("|%010s|\n", "hello");
	// j =    	  printf("|%2.c|\n", 'h');

	printf("our = %d, sys = %d\n", i, j);
}