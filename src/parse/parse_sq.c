/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:25:25 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/03/16 20:50:55 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_lstadd_sq(t_sq **lst, t_sq *new)
{
	t_sq	*tmp;

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

void	parse_sq(char **tab, t_sc *conf, int n_words)
{
	t_sq	*tmp_sq;

	if (n_words != 5)
		errors(-1);
	check_str(tab[1], 1, 1, 1);
	check_str(tab[2], 1, 1, 1);
	check_str(tab[3], 0, 1, 0);
	check_str(tab[4], 0, 0, 1);
	tmp_sq = malloc(sizeof(t_sq));
	tmp_sq->next = NULL;
	get_vector(tab[1], &tmp_sq->pos, 0);
	get_vector(tab[2], &tmp_sq->dir, 1);
	tmp_sq->side = ft_atof(tab[3]);
	get_color(tab[4], &tmp_sq->color);
	tmp_sq->xmin = tmp_sq->pos.x - (tmp_sq->side / 2);
	tmp_sq->xmax = tmp_sq->pos.x + (tmp_sq->side / 2);
	tmp_sq->ymin = tmp_sq->pos.y - (tmp_sq->side / 2);
	tmp_sq->ymax = tmp_sq->pos.y + (tmp_sq->side / 2);
	ft_lstadd_sq(&conf->sq, tmp_sq);
}
