/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:40:36 by jde-rus           #+#    #+#             */
/*   Updated: 2014/12/09 16:31:18 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src && (src[i] != '\0') && (i < n) && (i <= ft_strlen(dst)))
	{
		dst[i] = src[i];
		i++;
	}
	if (ft_strlen(src) < n)
		while (i < n)
			dst[i++] = '\0';
	return (dst);
}
