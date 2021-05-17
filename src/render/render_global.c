/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_global.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:43:24 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 16:41:48 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	exit_minirt(t_sc *sc)
{
	if (sc->win)
		mlx_destroy_window(sc->mlx, sc->win);
	exit(0);
}

int	cam_key(int keycode, t_sc *sc)
{
	int		addr_size;

	addr_size = (sc->res.y * sc->img.ll + sc->res.x * sc->img.bpp / 8);
	if (keycode == KEY_ESCAPE)
		exit_minirt(sc);
	cam_cycle(keycode, sc);
	ft_bzero(sc->img.addr, addr_size);
	render_cams(sc);
	return (1);
}

void	my_mlx_pixel_put(t_sc *sc, int x, int y, int color)
{
	char	*dst;

	dst = sc->img.addr + (y * sc->img.ll + x * (sc->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	render(t_sc *sc, t_img *img)
{
	sc->mlx = mlx_init();
	sc->win = mlx_new_window(sc->mlx, sc->res.x, sc->res.y, "miniRT");
	img->img = mlx_new_image(sc->mlx, sc->res.x, sc->res.y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->endian);
	mlx_hook(sc->win, 2, 0, cam_key, sc);
	mlx_hook(sc->win, 17, 0, exit_minirt, sc);
}
