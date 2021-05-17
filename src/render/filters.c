/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:25:10 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 02:07:51 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	filter_bnw(t_color *color)
{
	unsigned int	avg;

	avg = (color->r + color->g + color->b) / 3;
	color->r = avg;
	color->g = avg;
	color->b = avg;
}

void	filter_negative(t_color *color)
{
	color->r = 255 - color->r;
	color->g = 255 - color->g;
	color->b = 255 - color->b;
}

void	filter_sepia(t_color *color)
{
	t_color	sepia;

	sepia.r = color->r * 0.393 + color->g * 0.769 + color->b * 0.189;
	sepia.g = color->r * 0.349 + color->g * 0.686 + color->b * 0.168;
	sepia.b = color->r * 0.272 + color->g * 0.534 + color->b * 0.131;
	*color = sepia;
}

void	gamma_correction(t_color *color)
{
	double	gamma;

	gamma = 2.1;
	color->r = pow((double)color->r / 255, gamma) * 255;
	color->g = pow((double)color->g / 255, gamma) * 255;
	color->b = pow((double)color->b / 255, gamma) * 255;
}

void	filter_hub(t_color *color, int filtervalue)
{
	if (filtervalue == 1)
		filter_bnw(color);
	else if (filtervalue == 2)
		filter_negative(color);
	else if (filtervalue == 3)
		filter_sepia(color);
	else if (filtervalue == 4)
		gamma_correction(color);
}
