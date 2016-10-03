/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 15:27:22 by jde-rus           #+#    #+#             */
/*   Updated: 2015/01/05 17:04:04 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mylist;

	if (!(mylist = (t_list*)ft_memalloc(sizeof(mylist))))
		return (NULL);
	if (content != NULL)
	{
		if (!(mylist->content = malloc(sizeof(content))))
		{
			free(mylist);
			return (NULL);
		}
		ft_memcpy(mylist->content, content, content_size);
		mylist->content_size = content_size;
	}
	return (mylist);
}
