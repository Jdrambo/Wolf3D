/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:55:09 by jde-rus           #+#    #+#             */
/*   Updated: 2014/12/17 21:15:15 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char const *src)
{
	char *str;

	str = dst;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (str);
}
