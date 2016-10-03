/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:04:15 by jde-rus           #+#    #+#             */
/*   Updated: 2014/11/21 01:16:18 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (s2[j] == s1[i])
		{
			temp = i;
			while (s2[j] == s1[i + j] && s2[j] != '\0')
				j++;
			i = temp;
			if (s2[j] == '\0')
				return ((char*)(s1 + i));
			j = 0;
		}
		i++;
	}
	return (NULL);
}
