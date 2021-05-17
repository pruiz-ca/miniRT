/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:25:40 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 02:36:08 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_lstadd_cy(t_cy **lst, t_cy *new)
{
	t_cy	*tmp;

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

void	parse_cy(char **tab, t_sc *conf, int n_words)
{
	t_cy	*tmp_cy;

	if (n_words != 6)
		errors(-1);
	check_str(tab[1], 1, 1, 1);
	check_str(tab[2], 1, 1, 1);
	check_str(tab[3], 0, 1, 0);
	check_str(tab[4], 0, 1, 0);
	check_str(tab[5], 0, 0, 1);
	tmp_cy = malloc(sizeof(t_cy));
	tmp_cy->next = NULL;
	get_vector(tab[1], &tmp_cy->pos, 0);
	get_vector(tab[2], &tmp_cy->dir, 1);
	tmp_cy->radius = ft_atof(tab[3]) / 2;
	tmp_cy->height = ft_atof(tab[4]);
	get_color(tab[5], &tmp_cy->color);
	ft_lstadd_cy(&conf->cy, tmp_cy);
}
