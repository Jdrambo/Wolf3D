/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 20:32:11 by jde-rus           #+#    #+#             */
/*   Updated: 2014/12/16 20:18:38 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_strdup(const char *s1)
{
	char	*dst;

	if (s1 == NULL)
		return (NULL);
	dst = ft_strnew(ft_strlen(s1));
	ft_strcpy(dst, s1);
	return (dst);
}
