/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 01:20:38 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/15 20:22:24 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ray_sp(t_sp *sp, t_pxl *pxl, t_vector dir, t_vector from)
{
	t_intersect		eq;
	t_vector		ca;

	while (sp)
	{
		eq.is_valid = 0;
		ft_bzero(&eq, sizeof(t_intersect));
		ca = ft_vecsub(from, sp->pos);
		eq.a = ft_vecdot(dir, dir);
		eq.b = 2 * ft_vecdot(dir, ca);
		eq.c = ft_vecdot(ca, ca) - sp->radius * sp->radius;
		eq.discr = eq.b * eq.b - (4 * eq.a * eq.c);
		if (!(quad(&eq, &eq.a1, &eq.a2)) || !quad_isvalid(&eq.a1, &eq.a2))
			eq.is_valid++;
		if (eq.a1 < pxl->t && eq.a1 > 0 && eq.is_valid == 0)
		{
			pxl->t = eq.a1;
			pxl->color = sp->color;
			pxl->objpos = sp->pos;
			pxl->hitpnt = ft_vecsum(from, ft_vecsca(dir, pxl->t));
			pxl->normal = ft_vecnorm(ft_vecsub(pxl->hitpnt, sp->pos));
		}
		sp = sp->next;
	}
}
