/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_movement_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:03:32 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 16:27:55 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	obj_select(t_sc *sc, t_movelist *current_obj, int *idx)
{
	int			tmp_idx;

	tmp_idx = 0;
	while (1)
	{
		if (sp_cycle(sc, current_obj, idx, &tmp_idx))
			break ;
		if (pl_cycle(sc, current_obj, idx, &tmp_idx))
			break ;
		if (cy_cycle(sc, current_obj, idx, &tmp_idx))
			break ;
		if (sq_cycle(sc, current_obj, idx, &tmp_idx))
			break ;
		if (tr_cycle(sc, current_obj, idx, &tmp_idx))
			break ;
		break ;
	}
}

void	tr_movement(t_movelist *current_obj, int axis, double sum)
{
	if (axis == 1)
	{
		current_obj->pos1->x += sum;
		current_obj->pos2->x += sum;
		current_obj->pos3->x += sum;
	}
	if (axis == 2)
	{
		current_obj->pos1->y += sum;
		current_obj->pos2->y += sum;
		current_obj->pos3->y += sum;
	}
	if (axis == 3)
	{
		current_obj->pos1->z += sum;
		current_obj->pos2->z += sum;
		current_obj->pos3->z += sum;
	}
}

void	obj_movement(t_movelist *current_obj, int axis, double sum)
{
	if (current_obj->is_triangle == 1)
		tr_movement(current_obj, axis, sum);
	else
	{
		if (axis == 1)
			current_obj->pos1->x += sum;
		if (axis == 2)
			current_obj->pos1->y += sum;
		if (axis == 3)
			current_obj->pos1->z += sum;
	}
}

void	obj_movement_hub(int keycode, t_sc *sc)
{
	static t_movelist	current_obj;
	static int			idx;

	if (!idx || keycode == KEY_UP)
		idx = 0;
	if (!current_obj.pos1)
		obj_select(sc, &current_obj, &idx);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		obj_select(sc, &current_obj, &idx);
	if (keycode == KEY_I)
		obj_movement(&current_obj, 2, MOV_STEP);
	if (keycode == KEY_K)
		obj_movement(&current_obj, 2, -MOV_STEP);
	if (keycode == KEY_L)
		obj_movement(&current_obj, 1, MOV_STEP);
	if (keycode == KEY_J)
		obj_movement(&current_obj, 1, -MOV_STEP);
	if (keycode == KEY_U)
		obj_movement(&current_obj, 3, MOV_STEP);
	if (keycode == KEY_O)
		obj_movement(&current_obj, 3, -MOV_STEP);
}
