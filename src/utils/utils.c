/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:21:45 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/16 16:17:19 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	get_color(char *tab, t_color *color)
{
	char		**c;

	c = ft_split(tab, ',');
	if (c[3])
		errors(-1);
	color->r = ft_atoi(c[0]);
	color->g = ft_atoi(c[1]);
	color->b = ft_atoi(c[2]);
	ft_freetab(c);
	check_range(color->r, 0, 255);
	check_range(color->g, 0, 255);
	check_range(color->b, 0, 255);
	color->hex = ((color->r << 16) + (color->g << 8) + (color->b));
}

void	get_vector(char *tab, t_vector *vector, int neednorm)
{
	char		**v;

	v = ft_split(tab, ',');
	if (v[3])
		errors(-1);
	vector->x = ft_atof(v[0]);
	vector->y = ft_atof(v[1]);
	vector->z = ft_atof(v[2]);
	ft_freetab(v);
	if (neednorm == 1)
	{
		check_range(vector->x, -1, 1);
		check_range(vector->y, -1, 1);
		check_range(vector->z, -1, 1);
		*vector = ft_vecnorm(*vector);
	}
}

int	quad(t_intersect *eq, double *ans1, double *ans2)
{
	double	tmp;

	if (eq->discr < 0)
		return (0);
	else if (eq->discr == 0)
	{
		*ans1 = -0.5 * eq->b / eq->a;
		*ans2 = *ans1;
	}
	else
	{
		if (eq->b > 0)
			tmp = -0.5 * (eq->b + sqrt(eq->discr));
		else
			tmp = -0.5 * (eq->b - sqrt(eq->discr));
		*ans1 = tmp / eq->a;
		*ans2 = eq->c / tmp;
	}
	return (1);
}

int	quad_isvalid(double *ans1, double *ans2)
{
	if (*ans1 > *ans2)
		ft_swap_double(ans1, ans2);
	if (*ans1 < 0)
	{
		*ans1 = *ans2;
		if (*ans1 < 0)
			return (0);
	}
	if (*ans1 > 0)
		return (1);
	return (0);
}

int	quad_cy(t_intersect *eq, t_vector dir, t_vector from, t_cy *cy)
{
	t_vector	len;
	t_vector	pnt;
	double		max;

	if (eq->a1 > eq->a2 || eq->a1 < 0)
		ft_swap_double(&eq->a1, &eq->a2);
	max = sqrt(pow(cy->height / 2, 2) + pow(cy->radius, 2));
	pnt = ft_vecsum(from, ft_vecsca(dir, eq->a1));
	len = ft_vecsub(pnt, cy->pos);
	if (ft_veclen(len) > max)
		ft_swap_double(&eq->a1, &eq->a2);
	pnt = ft_vecsum(from, ft_vecsca(dir, eq->a1));
	len = ft_vecsub(pnt, cy->pos);
	if (ft_veclen(len) > max)
		return (0);
	return (1);
}
