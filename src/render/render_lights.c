/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:02:40 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 02:10:15 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	light_range(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
	if (color->r < 0)
		color->r = 0;
	if (color->g < 0)
		color->g = 0;
	if (color->b < 0)
		color->b = 0;
}

void	get_lights(t_sc *sc, t_light *light, t_pxl *pxl, t_pxl *tmp)
{
	t_vector	lightd;
	t_vector	lightd_n;
	double		lightcos;
	double		objdst;

	while (light)
	{
		lightd = ft_vecsub(light->pos, pxl->acnepnt);
		lightd_n = ft_vecnorm(lightd);
		lightcos = ft_vecdot(lightd_n, pxl->normal);
		tmp->t = INFINITY;
		ray_tr(sc->tr, tmp, lightd_n, pxl->acnepnt);
		ray_pl(sc->pl, tmp, lightd_n, pxl->acnepnt);
		ray_sp(sc->sp, tmp, lightd_n, pxl->acnepnt);
		ray_sq(sc->sq, tmp, lightd_n, pxl->acnepnt);
		ray_cy(sc->cy, tmp, lightd_n, pxl->acnepnt);
		objdst = ft_veclen(ft_vecsub(tmp->hitpnt, pxl->hitpnt));
		if ((tmp->t == INFINITY || objdst >= ft_veclen(lightd)) && lightcos > 0)
		{
			pxl->lcolor.r += light->color.r * light->bright * lightcos;
			pxl->lcolor.g += light->color.g * light->bright * lightcos;
			pxl->lcolor.b += light->color.b * light->bright * lightcos;
		}
		light = light->next;
	}
}

void	render_lights(t_sc *sc, t_light *light, t_pxl *pxl)
{
	t_pxl		tmp;
	t_light		*tmplight;

	tmp = *pxl;
	tmplight = light;
	pxl->lcolor = (t_color){0, 0, 0, 0};
	pxl->acnepnt = ft_vecsum(pxl->hitpnt, ft_vecsca(pxl->normal, 0.001));
	get_lights(sc, tmplight, pxl, &tmp);
	pxl->lcolor.r += sc->amb.color.r * sc->amb.bright;
	pxl->lcolor.g += sc->amb.color.g * sc->amb.bright;
	pxl->lcolor.b += sc->amb.color.b * sc->amb.bright;
	pxl->color.r = pxl->color.r * pxl->lcolor.r / 255;
	pxl->color.g = pxl->color.g * pxl->lcolor.g / 255;
	pxl->color.b = pxl->color.b * pxl->lcolor.b / 255;
	filter_hub(&pxl->color, sc->filter);
	light_range(&pxl->color);
	pxl->color.hex = (pxl->color.r << 16 | pxl->color.g << 8 | pxl->color.b);
}
