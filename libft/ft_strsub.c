/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:56:16 by jde-rus           #+#    #+#             */
/*   Updated: 2014/12/10 19:52:31 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	finish;

	if (!s || start > ft_strlen(s))
		return (NULL);
	dst = (char*)malloc((sizeof(*dst) * len) + 1);
	finish = start + len;
	i = 0;
	if (!dst)
		return (NULL);
	while (dst && s && start < finish && s[start] != '\0')
	{
		dst[i] = s[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
