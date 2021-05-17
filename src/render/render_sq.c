/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:14:49 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/15 20:14:46 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_sq(t_sq *sq, t_vector hpnt)
{
	if ((fabs(hpnt.x - sq->pos.x) < (sq->side / 2))
		&& (fabs(hpnt.y - sq->pos.y) < (sq->side / 2))
		&& (fabs(hpnt.z - sq->pos.z) < (sq->side / 2)))
		return (1);
	return (0);
}

double	denom(t_vector *tmp_dir, t_vector dir)
{
	double	denom;

	denom = ft_vecdot(*tmp_dir, dir);
	if (denom < -EPSILON)
		*tmp_dir = ft_vecsca(*tmp_dir, -1);
	denom = ft_vecdot(*tmp_dir, dir);
	return (denom);
}

void	ray_sq(t_sq *sq, t_pxl *pxl, t_vector dir, t_vector from)
{
	double		t;
	t_vector	hpnt;
	t_vector	tmp;

	while (sq)
	{
		tmp = sq->dir;
		if (denom(&tmp, dir) > EPSILON)
		{
			t = ft_vecdot(ft_vecsub(sq->pos, from), tmp) / denom(&tmp, dir);
			if (t < pxl->t && t >= 0)
			{
				hpnt = ft_vecsum(from, ft_vecsca(dir, t));
				if (check_sq(sq, hpnt) == 1)
				{
					pxl->hitpnt = hpnt;
					pxl->t = t;
					pxl->color = sq->color;
					pxl->objpos = sq->pos;
					pxl->normal = ft_vecnorm(ft_vecsca(tmp, -1));
				}
			}
		}
		sq = sq->next;
	}
}
