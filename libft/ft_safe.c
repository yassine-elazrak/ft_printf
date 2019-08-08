/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:18:05 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/08 21:02:57 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_safe(char *str, char *tmp)
{
	ft_strdel(&str);
	str = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (str);
}
