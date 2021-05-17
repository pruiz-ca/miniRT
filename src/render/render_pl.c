/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:14:49 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/16 15:37:25 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ray_pl(t_pl *pl, t_pxl *pxl, t_vector dir, t_vector from)
{
	double		t;
	double		denom;
	t_vector	tmp_dir;

	while (pl)
	{
		tmp_dir = pl->dir;
		denom = ft_vecdot(tmp_dir, dir);
		if (denom < -EPSILON && ft_vecdot(pl->dir, from))
			tmp_dir = ft_vecsca(tmp_dir, -1);
		denom = ft_vecdot(tmp_dir, dir);
		if (denom > EPSILON)
		{
			t = ft_vecdot(ft_vecsub(pl->pos, from), tmp_dir) / denom;
			if (t < pxl->t && t >= 0)
			{
				pxl->t = t;
				pxl->color = pl->color;
				pxl->objpos = pl->pos;
				pxl->normal = ft_vecnorm(ft_vecsca(tmp_dir, -1));
				pxl->hitpnt = ft_vecsum(from, ft_vecsca(dir, pxl->t));
			}
		}
		pl = pl->next;
	}
}
