/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:31:08 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 16:07:37 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	key_press(int keycode, t_sc *sc)
{
	int		addr_size;

	addr_size = (sc->res.y * sc->img.ll + sc->res.x * sc->img.bpp / 8);
	if (keycode == KEY_ESCAPE)
		exit_minirt(sc);
	cam_movement(keycode, sc);
	cam_rotation(keycode, sc);
	cam_filter(keycode, sc);
	cam_cycle(keycode, sc);
	obj_movement_hub(keycode, sc);
	ft_bzero(sc->img.addr, addr_size);
	multithread(sc);
	return (1);
}

t_vector	get_mousedir(t_sc *conf, double posx, double posy)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	ans;

	v1 = ft_vecsca(conf->cam->mat[0], posx);
	v2 = ft_vecsca(conf->cam->mat[1], -posy);
	ans = ft_vecsum(conf->cam->pxldir_gen, ft_vecsum(v1, v2));
	return (ft_vecnorm(ans));
}

int	mouse_press(int keycode, int x, int y, t_sc *sc)
{
	int		addr_size;

	addr_size = (sc->res.y * sc->img.ll + sc->res.x * sc->img.bpp / 8);
	if (keycode == 2 && x > 0 && y > 0)
	{
		sc->cam->dir = get_mousedir(sc, x, y);
		transf_matrix(sc->cam);
		get_pxldir_gen(sc, sc->cam);
		ft_bzero(sc->img.addr, addr_size);
		multithread(sc);
	}
	return (1);
}
