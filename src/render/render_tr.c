/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:28:36 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/15 20:21:58 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	get_tr(t_tr *tr, t_intersect *eq, t_vector dir, t_vector from)
{
	eq->is_valid = 0;
	eq->edge1 = ft_vecsub(tr->pos2, tr->pos1);
	eq->edge2 = ft_vecsub(tr->pos3, tr->pos1);
	eq->pvec = ft_vecx(dir, eq->edge2);
	eq->det = ft_vecdot(eq->edge1, eq->pvec);
	if (eq->det > -EPSILON && eq->det < EPSILON)
		eq->is_valid++;
	eq->det_inv = 1 / eq->det;
	eq->tvec = ft_vecsub(from, tr->pos1);
	eq->ans.x = ft_vecdot(eq->tvec, eq->pvec) * eq->det_inv;
	if (eq->ans.x < 0 || eq->ans.x > 1)
		eq->is_valid++;
	eq->qvec = ft_vecx(eq->tvec, eq->edge1);
	eq->ans.y = ft_vecdot(dir, eq->qvec) * eq->det_inv;
	if (eq->ans.y < 0 || eq->ans.x + eq->ans.y > 1)
		eq->is_valid++;
}

void	ray_tr(t_tr *tr, t_pxl *pxl, t_vector dir, t_vector from)
{
	t_intersect	eq;
	double		t;

	while (tr)
	{
		get_tr(tr, &eq, dir, from);
		t = ft_vecdot(eq.edge2, eq.qvec) * eq.det_inv;
		if (t < pxl->t && t >= 0 && eq.is_valid == 0)
		{
			pxl->t = t;
			pxl->color = tr->color;
			pxl->objpos = tr->pos1;
			pxl->hitpnt = ft_vecsum(from, ft_vecsca(dir, t));
			pxl->normal = ft_vecnorm(ft_vecx(eq.edge1, eq.edge2));
			if (ft_vecdot(dir, pxl->normal) > 0)
				pxl->normal = ft_vecnorm(ft_vecx(eq.edge2, eq.edge1));
		}
		tr = tr->next;
	}
}
