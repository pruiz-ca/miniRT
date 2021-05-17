/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vcolorsum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:32:56 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/15 23:21:14 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	ft_vcolorsum(t_color *c1, t_color *c2)
{
	t_color	sum;

	sum.r = c1->r + c2->r;
	sum.g = c1->g + c2->g;
	sum.b = c1->b + c2->b;
	return (sum);
}
