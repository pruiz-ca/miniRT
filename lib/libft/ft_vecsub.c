/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:33:41 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/15 23:20:52 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	ft_vecsub(t_vector plus, t_vector minus)
{
	t_vector	sub;

	sub.x = plus.x - minus.x;
	sub.y = plus.y - minus.y;
	sub.z = plus.z - minus.z;
	return (sub);
}
