/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:22:42 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/16 17:55:58 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_cy(t_cy *cy, t_vector hpnt)
{
	t_vector	pmax;
	t_vector	pmin;
	double		capmin;
	double		capmax;

	pmin = ft_vecsum(cy->pos, ft_vecsca(cy->dir, -0.5 * cy->height));
	pmax = ft_vecsum(cy->pos, ft_vecsca(cy->dir, 0.5 * cy->height));
	capmin = ft_vecdot(ft_vecsub(hpnt, pmin), ft_vecsub(hpnt, pmin));
	capmax = ft_vecdot(ft_vecsub(hpnt, pmax), ft_vecsub(hpnt, pmax));
	if (ft_vecdot(cy->dir, ft_vecsub(hpnt, pmin)) > 0
		&& ft_vecdot(cy->dir, ft_vecsub(hpnt, pmax)) < 0)
		return (1);
	if (capmin < pow(cy->radius, 2) || capmax < pow(cy->radius, 2))
		return (1);
	return (0);
}

t_vector	normal_cy(t_cy *cy, t_vector hpnt)
{
	t_vector	hpnt_pos;
	t_vector	hpnt_height;
	t_vector	normal;

	hpnt_pos = ft_vecsub(hpnt, cy->pos);
	hpnt_height = ft_vecsca(cy->dir, ft_vecdot(cy->dir, hpnt_pos));
	normal = ft_vecnorm(ft_vecsub(hpnt_pos, hpnt_height));
	return (normal);
}

void	get_cy(t_cy *cy, t_intersect *eq, t_vector dir, t_vector from)
{
	t_vector	helper_a;
	t_vector	helper_b;

	eq->cy_p = ft_vecsub(from, cy->pos);
	helper_a = ft_vecsca(cy->dir, ft_vecdot(dir, cy->dir));
	eq->cy_a = ft_vecsub(dir, helper_a);
	helper_b = ft_vecsca(cy->dir, ft_vecdot(eq->cy_p, cy->dir));
	eq->cy_b = ft_vecsub(eq->cy_p, helper_b);
	eq->a = ft_vecdot(eq->cy_a, eq->cy_a);
	eq->b = 2 * ft_vecdot(eq->cy_a, eq->cy_b);
	eq->c = ft_vecdot(eq->cy_b, eq->cy_b) - (cy->radius * cy->radius);
	eq->discr = eq->b * eq->b - (4 * eq->a * eq->c);
}

void	ray_cy(t_cy *cy, t_pxl *pxl, t_vector dir, t_vector from)
{
	t_intersect	eq;
	t_vector	hpnt;

	while (cy)
	{
		eq.is_valid = 0;
		get_cy(cy, &eq, dir, from);
		if (!(quad(&eq, &eq.a1, &eq.a2)) || !quad_cy(&eq, dir, from, cy))
			eq.is_valid++;
		if (eq.a1 < pxl->t && eq.a1 > 0 && eq.is_valid == 0)
		{
			hpnt = ft_vecsum(from, ft_vecsca(dir, eq.a1));
			if (check_cy(cy, hpnt))
			{
				pxl->t = eq.a1;
				pxl->color = cy->color;
				pxl->objpos = cy->pos;
				pxl->hitpnt = hpnt;
				pxl->normal = normal_cy(cy, hpnt);
				if (ft_vecdot(pxl->normal, from) < 0)
					pxl->normal = ft_vecsca(pxl->normal, -1);
			}
		}
		cy = cy->next;
	}
}
