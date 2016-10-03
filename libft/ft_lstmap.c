/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 18:12:50 by jde-rus           #+#    #+#             */
/*   Updated: 2015/01/13 04:32:00 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*ret;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	ret = tmp;
	while ((lst = lst->next))
	{
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (ret);
}
