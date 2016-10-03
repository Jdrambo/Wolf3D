/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:11:54 by jde-rus           #+#    #+#             */
/*   Updated: 2015/01/24 00:14:13 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void *ft_memalloc(size_t size)
{
	void *setmem;

	if (size == 0)
		return (NULL);
	setmem = NULL;
	setmem = (void *)malloc(size);
	if (setmem == NULL)
		return (NULL);
	ft_bzero(setmem, size);
	return (setmem);
}
