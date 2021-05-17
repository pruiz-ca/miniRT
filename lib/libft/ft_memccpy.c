/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:16:26 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/02/18 21:34:31 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*usdst;
	unsigned char	*ussrc;
	int				i;

	usdst = (unsigned char *)dst;
	ussrc = (unsigned char *)src;
	i = 0;
	while (i < (int)n)
	{
		usdst[i] = ussrc[i];
		if (ussrc[i] == (unsigned char)c)
			return (&usdst[i + 1]);
		i++;
	}
	return (NULL);
}
