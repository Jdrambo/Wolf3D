/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 23:57:20 by jde-rus           #+#    #+#             */
/*   Updated: 2014/12/11 19:48:27 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t i;
	size_t j;

	len = ft_strlen(dst);
	i = len;
	j = 0;
	if (size < len)
		return (ft_strlen(src) + size);
	while (src[j] && (len + j + 1) < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len + ft_strlen(src));
}
