/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 01:37:37 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/05/17 17:09:26 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	cam_movement(int keycode, t_sc *sc)
{
	if (keycode == KEY_A)
		sc->cam->pos.x -= MOV_STEP;
	if (keycode == KEY_D)
		sc->cam->pos.x += MOV_STEP;
	if (keycode == KEY_SHIFT_LEFT)
		sc->cam->pos.y += MOV_STEP;
	if (keycode == KEY_CTRL_LEFT)
		sc->cam->pos.y -= MOV_STEP;
	if (keycode == KEY_S)
		sc->cam->pos.z += MOV_STEP;
	if (keycode == KEY_W)
		sc->cam->pos.z -= MOV_STEP;
}

void	cam_rotation(int keycode, t_sc *sc)
{
	if (keycode == KEY_T)
		rotate_x(sc, &sc->cam->dir, 1);
	if (keycode == KEY_G)
		rotate_x(sc, &sc->cam->dir, -1);
	if (keycode == KEY_F)
		rotate_y(sc, &sc->cam->dir, 1);
	if (keycode == KEY_H)
		rotate_y(sc, &sc->cam->dir, -1);
}

void	cam_filter(int keycode, t_sc *sc)
{
	if (keycode == KEY_0)
		sc->filter = 0;
	if (keycode == KEY_1)
		sc->filter = 1;
	if (keycode == KEY_2)
		sc->filter = 2;
	if (keycode == KEY_3)
		sc->filter = 3;
	if (keycode == KEY_4)
		sc->filter = 4;
}
