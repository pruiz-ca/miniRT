/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:24:16 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/03/15 15:20:48 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_lstadd_light(t_light **lst, t_light *new)
{
	t_light	*tmp;

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

void	parse_light(char **tab, t_sc *conf, int n_words)
{
	t_light	*tmp_light;

	if (n_words != 4)
		errors(-1);
	check_str(tab[1], 1, 1, 1);
	check_str(tab[2], 0, 1, 0);
	check_str(tab[3], 0, 0, 1);
	tmp_light = malloc(sizeof(t_light));
	tmp_light->next = NULL;
	get_vector(tab[1], &tmp_light->pos, 0);
	get_color(tab[3], &tmp_light->color);
	tmp_light->bright = ft_atof(tab[2]);
	check_range(tmp_light->bright, 0, 1);
	ft_lstadd_light(&conf->light, tmp_light);
}
