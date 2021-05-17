/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 02:09:39 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/16 18:02:41 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	rotate_x(t_sc *sc, t_vector *dir, int sign)
{
	double		angle;
	t_vector	tmp;

	angle = ft_degtorad(1);
	tmp = *dir;
	if (sign == 1)
	{
		dir->y = (cos(angle) * tmp.y) - (sin(angle) * tmp.z);
		dir->z = (sin(angle) * tmp.y) + (cos(angle) * tmp.z);
	}
	else
	{
		dir->y = cos(-angle) * tmp.y - sin(-angle) * tmp.z;
		dir->z = sin(-angle) * tmp.y + cos(-angle) * tmp.z;
	}
	*dir = ft_vecnorm(*dir);
	transf_matrix(sc->cam);
	get_pxldir_gen(sc, sc->cam);
}

void	rotate_y(t_sc *sc, t_vector *dir, int sign)
{
	double		angle;
	t_vector	tmp;

	angle = ft_degtorad(1);
	tmp = *dir;
	if (sign == 1)
	{
		dir->x = cos(angle) * dir->x + sin(angle) * dir->z;
		dir->z = -sin(angle) * dir->x + cos(angle) * dir->z;
		dir->y = tmp.y;
	}
	else
	{
		dir->x = cos(-angle) * dir->x + sin(-angle) * dir->z;
		dir->z = -sin(-angle) * dir->x + cos(-angle) * dir->z;
		dir->y = tmp.y;
	}
	*dir = ft_vecnorm(*dir);
	transf_matrix(sc->cam);
	get_pxldir_gen(sc, sc->cam);
}
