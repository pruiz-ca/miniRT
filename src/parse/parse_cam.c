/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:06:11 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 16:44:35 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_lstadd_cam(t_cam **lst, t_cam *new)
{
	t_cam	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp)
			tmp->next = new;
	}
}

void	transf_matrix(t_cam *cam)
{
	t_vector	fwd;
	t_vector	right;
	t_vector	up;
	t_vector	tmp;

	tmp = (t_vector){0, 1, 0};
	if (cam->dir.x == 0 && (cam->dir.y == 1 || cam->dir.y == -1)
		&& cam->dir.z == 0)
		tmp = (t_vector){0, 0, 1};
	fwd = cam->dir;
	right = ft_vecx(fwd, tmp);
	up = ft_vecx(right, fwd);
	cam->mat[0] = right;
	cam->mat[1] = up;
	cam->mat[2] = fwd;
	cam->mat[3] = cam->pos;
}

void	get_pxldir_gen(t_sc *conf, t_cam *cam)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;

	v1 = ft_vecsca(cam->mat[0], (conf->res.x * -0.5));
	v2 = ft_vecsca(cam->mat[1], (conf->res.y * 0.5));
	v3 = ft_vecsca(cam->mat[2], conf->res.y / (2 * cam->fov_w));
	cam->pxldir_gen = ft_vecsum(v3, ft_vecsum(v1, v2));
	if (cam->pxldir_gen.x < 0.0001 && cam->pxldir_gen.x > -0.0001)
		cam->pxldir_gen.x = 0;
	if (cam->pxldir_gen.y < 0.0001 && cam->pxldir_gen.y > -0.0001)
		cam->pxldir_gen.y = 0;
	if (cam->pxldir_gen.z < 0.0001 && cam->pxldir_gen.z > -0.0001)
		cam->pxldir_gen.z = 0;
}

void	parse_cam(char **tab, t_sc *conf, int n_words)
{
	t_cam	*tmp_cam;

	if (n_words != 4)
		errors(-1);
	check_str(tab[1], 1, 1, 1);
	check_str(tab[2], 1, 1, 1);
	check_str(tab[3], 0, 0, 0);
	tmp_cam = malloc(sizeof(t_cam));
	tmp_cam->next = NULL;
	get_vector(tab[1], &tmp_cam->pos, 0);
	get_vector(tab[2], &tmp_cam->dir, 1);
	tmp_cam->dir = ft_vecnorm(tmp_cam->dir);
	tmp_cam->fov = ft_atoi(tab[3]);
	check_range(tmp_cam->fov, 0, 180);
	tmp_cam->fov_w = atan(ft_degtorad(tmp_cam->fov * 0.5));
	transf_matrix(tmp_cam);
	get_pxldir_gen(conf, tmp_cam);
	ft_lstadd_cam(&conf->cam, tmp_cam);
}

void	cam_cycle(int keycode, t_sc *sc)
{
	if (keycode == KEY_RIGHT)
	{
		if (sc->cam->next)
			sc->cam = sc->cam->next;
		else
			sc->cam = &sc->first_cam;
	}
	if (keycode == KEY_LEFT)
		sc->cam = &sc->first_cam;
}
