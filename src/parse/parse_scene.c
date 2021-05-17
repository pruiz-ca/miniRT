/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:20:05 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 18:24:38 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	check_res(int *x, int *y)
{
	int	xmin;
	int	xmax;
	int	ymin;
	int	ymax;

	xmin = 640;
	ymin = 480;
	xmax = 2560;
	ymax = 1398;
	if (*x < xmin)
		*x = xmin;
	if (*y < ymin)
		*y = ymin;
	if (*x > xmax)
		*x = xmax;
	if (*y > ymax)
		*y = ymax;
}

void	parse_res(char **tab, t_sc *conf, int n_words)
{
	if (n_words != 3)
		errors(-1);
	if (conf->res.enabled == 1)
		errors(-6);
	conf->res.enabled = 1;
	check_str(tab[1], 0, 0, 0);
	check_str(tab[2], 0, 0, 0);
	conf->res.x = ft_atoi(tab[1]);
	conf->res.y = ft_atoi(tab[2]);
	check_res(&conf->res.x, &conf->res.y);
	conf->res.ratio = conf->res.x / conf->res.y;
}

void	parse_amb(char **tab, t_sc *conf, int n_words)
{
	if (n_words != 3)
		errors(-1);
	if (conf->amb.enabled == 1)
		errors(-6);
	conf->amb.enabled = 1;
	check_str(tab[1], 0, 1, 0);
	check_str(tab[2], 0, 0, 1);
	conf->amb.bright = ft_atof(tab[1]);
	get_color(tab[2], &conf->amb.color);
	check_range(conf->amb.bright, 0, 1);
}
