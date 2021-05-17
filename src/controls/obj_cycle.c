/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:03:32 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 16:15:36 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	sp_cycle(t_sc *sc, t_movelist *current_obj, int *idx, int *tmp_idx)
{
	t_sp	*tmp_sp;

	tmp_sp = sc->sp;
	while (tmp_sp)
	{
		if (*tmp_idx == *idx)
		{
			current_obj->is_triangle = 0;
			current_obj->pos1 = &tmp_sp->pos;
			(*idx)++;
			return (1);
		}
		(*tmp_idx)++;
		tmp_sp = tmp_sp->next;
	}
	return (0);
}

int	pl_cycle(t_sc *sc, t_movelist *current_obj, int *idx, int *tmp_idx)
{
	t_pl	*tmp_pl;

	tmp_pl = sc->pl;
	while (tmp_pl)
	{
		if (*tmp_idx == *idx)
		{
			current_obj->is_triangle = 0;
			current_obj->pos1 = &tmp_pl->pos;
			(*idx)++;
			return (1);
		}
		(*tmp_idx)++;
		tmp_pl = tmp_pl->next;
	}
	return (0);
}

int	cy_cycle(t_sc *sc, t_movelist *current_obj, int *idx, int *tmp_idx)
{
	t_cy	*tmp_cy;

	tmp_cy = sc->cy;
	while (tmp_cy)
	{
		if (*tmp_idx == *idx)
		{
			current_obj->is_triangle = 0;
			current_obj->pos1 = &tmp_cy->pos;
			(*idx)++;
			return (1);
		}
		(*tmp_idx)++;
		tmp_cy = tmp_cy->next;
	}
	return (0);
}

int	sq_cycle(t_sc *sc, t_movelist *current_obj, int *idx, int *tmp_idx)
{
	t_sq	*tmp_sq;

	tmp_sq = sc->sq;
	while (tmp_sq)
	{
		if (*tmp_idx == *idx)
		{
			current_obj->is_triangle = 0;
			current_obj->pos1 = &tmp_sq->pos;
			(*idx)++;
			return (1);
		}
		(*tmp_idx)++;
		tmp_sq = tmp_sq->next;
	}
	return (0);
}

int	tr_cycle(t_sc *sc, t_movelist *current_obj, int *idx, int *tmp_idx)
{
	t_tr	*tmp_tr;

	tmp_tr = sc->tr;
	while (tmp_tr)
	{
		if (*tmp_idx == *idx)
		{
			current_obj->is_triangle = 1;
			current_obj->pos1 = &tmp_tr->pos1;
			current_obj->pos2 = &tmp_tr->pos2;
			current_obj->pos3 = &tmp_tr->pos3;
			(*idx)++;
			return (1);
		}
		(*tmp_idx)++;
		tmp_tr = tmp_tr->next;
	}
	return (0);
}
