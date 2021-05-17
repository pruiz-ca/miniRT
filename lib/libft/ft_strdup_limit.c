/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_limit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:06:57 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/15 22:25:25 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_limit(const char *src, int end)
{
	char	*p;
	int		i;

	p = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (src[i] && i < end)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
