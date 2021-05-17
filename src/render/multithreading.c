/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:02:40 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 01:54:13 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	check_collision_mt(t_sc *conf)
{
	ray_pl(conf->pl, &conf->pxl, conf->pxl.dir, conf->cam->pos);
	ray_sp(conf->sp, &conf->pxl, conf->pxl.dir, conf->cam->pos);
	ray_tr(conf->tr, &conf->pxl, conf->pxl.dir, conf->cam->pos);
	ray_sq(conf->sq, &conf->pxl, conf->pxl.dir, conf->cam->pos);
	ray_cy(conf->cy, &conf->pxl, conf->pxl.dir, conf->cam->pos);
}

void	render_cams_mt(t_thread *c)
{
	int			j;

	while (c->start < c->end)
	{
		j = -1;
		while (++j < c->sc.res.x)
		{
			c->sc.pxl.t = INFINITY;
			get_pixldir(&c->sc, j, c->start);
			check_collision_mt(&c->sc);
			if (c->sc.pxl.t != INFINITY)
			{
				render_lights(&c->sc, c->sc.light, &c->sc.pxl);
				my_mlx_pixel_put(&c->sc, j, c->start, c->sc.pxl.color.hex);
			}
		}
		c->start++;
	}
	pthread_exit(NULL);
}

void	multithread(t_sc *sc)
{
	int			i;
	int			lines;
	pthread_t	pid[MAXTHREADS];
	t_thread	tid[MAXTHREADS];

	lines = sc->res.y / MAXTHREADS;
	i = -1;
	while (++i < MAXTHREADS)
	{
		tid[i].start = i * lines;
		tid[i].end = ((i + 1) * lines);
		ft_memcpy(&tid[i].sc, sc, sizeof(*sc));
		pthread_create(&pid[i], NULL, (void *)render_cams_mt, &tid[i]);
	}
	while (--i >= 0)
		pthread_join(pid[i], NULL);
	if (sc->screenshot == 1)
		bmp_create(sc);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img.img, 0, 0);
}

void	render_mt(t_sc *sc, t_img *img)
{
	sc->mlx = mlx_init();
	sc->win = mlx_new_window(sc->mlx, sc->res.x, sc->res.y, "miniRT");
	img->img = mlx_new_image(sc->mlx, sc->res.x, sc->res.y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->endian);
	mlx_hook(sc->win, 4, 0, mouse_press, sc);
	mlx_hook(sc->win, 2, 0, key_press, sc);
	mlx_hook(sc->win, 17, 0, exit_minirt, sc);
}
