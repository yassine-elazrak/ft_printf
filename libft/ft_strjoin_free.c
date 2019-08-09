/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:33:02 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/09 06:21:14 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len1 + len2) + 1)))
		exit(1);
	while (i < (len1 + len2))
	{
		if (i < len1)
			str[i] = s1[i];
		else
			str[i] = s2[i - len1];
		i++;
	}
	ft_strdel(&s1);
	ft_strdel(&s2);
	str[i] = '\0';
	return (str);
}
