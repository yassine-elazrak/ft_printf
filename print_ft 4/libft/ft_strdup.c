/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:00:04 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/21 19:13:45 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dst;

	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	ft_strcpy(dst, s);
	return (dst);
}
