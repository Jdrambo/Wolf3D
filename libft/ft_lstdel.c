/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 17:42:56 by jde-rus           #+#    #+#             */
/*   Updated: 2015/01/21 19:24:24 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *current;

	if (!alst)
		return ;
	current = *alst;
	while (current)
	{
		if (del)
			(*del)(current->content, current->content_size);
		free(current);
		current = current->next;
	}
	*alst = 0;
}
