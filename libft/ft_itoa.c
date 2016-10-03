/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:14:25 by jde-rus           #+#    #+#             */
/*   Updated: 2014/11/27 19:53:11 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_len(int n)
{
	size_t	i;
	int		nbr;

	i = 0;
	if (n == 0)
		return (1);
	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 1)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*dest;
	size_t	len;

	if (n == 0)
		return (strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_get_len(n);
	if (n < 0)
		len++;
	dest = ft_strnew(len);
	if (!dest || !n)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		dest[0] = '-';
	}
	while (dest && n > 0)
	{
		dest[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (dest);
}
