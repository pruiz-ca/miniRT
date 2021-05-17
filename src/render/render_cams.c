/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cams.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:23:45 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 16:44:25 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	get_pixldir(t_sc *conf, double posx, double posy)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	ans;

	v1 = ft_vecsca(conf->cam->mat[0], posx);
	v2 = ft_vecsca(conf->cam->mat[1], -posy);
	ans = ft_vecsum(conf->cam->pxldir_gen, ft_vecsum(v1, v2));
	conf->pxl.dir = ft_vecnorm(ans);
}

void	check_collision(t_sc *conf)
{
	ray_pl(conf->pl, &conf->pxl, conf->pxl.dir, conf->cam->pos);
	ray_sp(conf->sp, &conf->pxl, conf->pxl.dir, conf->cam->pos);
	ray_tr(conf->tr, &conf->pxl, conf->pxl.dir, conf->cam->pos);
	ray_sq(conf->sq, &conf->pxl, conf->pxl.dir, conf->cam->pos);
	ray_cy(conf->cy, &conf->pxl, conf->pxl.dir, conf->cam->pos);
}

void	render_cams(t_sc *conf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < conf->res.y)
	{
		j = -1;
		while (++j < conf->res.x)
		{
			conf->pxl.t = INFINITY;
			get_pixldir(conf, j, i);
			check_collision(conf);
			if (conf->pxl.t != INFINITY)
			{
				render_lights(conf, conf->light, &conf->pxl);
				my_mlx_pixel_put(conf, j, i, conf->pxl.color.hex);
			}
		}
	}
	if (conf->screenshot == 1)
		bmp_create(conf);
	mlx_put_image_to_window(conf->mlx, conf->win, conf->img.img, 0, 0);
}
