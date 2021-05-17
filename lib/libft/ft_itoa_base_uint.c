/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:45:38 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/15 21:43:13 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_count(unsigned int n, unsigned int base)
{
	size_t	i;

	i = 1;
	while ((n >= base) > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_uint(unsigned int n, unsigned int base)
{
	char	*str;
	int		len;

	len = ft_int_count(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		if (n % base < 10)
			str[--len] = n % base + '0';
		else
			str[--len] = n % base - 10 + 'a';
		n /= base;
	}
	return (str);
}
