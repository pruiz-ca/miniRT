/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecxmat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 04:15:30 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/15 23:20:48 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	ft_vecxmat(t_vector mat[4], t_vector v)
{
	t_vector	ans;

	ans.x = v.x * mat[0].x + v.y * mat[1].x + v.z * mat[2].x;
	ans.y = v.x * mat[0].y + v.y * mat[1].y + v.z * mat[2].y;
	ans.z = v.x * mat[0].z + v.y * mat[1].z + v.z * mat[2].z;
	return (ans);
}
