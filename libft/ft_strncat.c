/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:06:04 by jde-rus           #+#    #+#             */
/*   Updated: 2014/12/11 19:47:19 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = ft_strlen(dst);
	j = 0;
	while ((src[j] != '\0') && (j < n))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst);
}
