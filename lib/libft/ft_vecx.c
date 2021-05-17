/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:32:07 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/15 23:20:44 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	ft_vecx(t_vector v1, t_vector v2)
{
	t_vector	ans;

	ans.x = v1.y * v2.z - v2.y * v1.z;
	ans.y = v2.x * v1.z - v1.x * v2.z;
	ans.z = v1.x * v2.y - v2.x * v1.y;
	return (ans);
}
