/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:25:28 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/03/15 15:21:21 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_lstadd_tr(t_tr **lst, t_tr *new)
{
	t_tr	*tmp;

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

void	parse_tr(char **tab, t_sc *conf, int n_words)
{
	t_tr	*tmp_tr;

	if (n_words != 5)
		errors(-1);
	check_str(tab[1], 1, 1, 1);
	check_str(tab[2], 1, 1, 1);
	check_str(tab[3], 1, 1, 1);
	check_str(tab[4], 0, 0, 1);
	tmp_tr = malloc(sizeof(t_tr));
	tmp_tr->next = NULL;
	get_vector(tab[1], &tmp_tr->pos1, 0);
	get_vector(tab[2], &tmp_tr->pos2, 0);
	get_vector(tab[3], &tmp_tr->pos3, 0);
	get_color(tab[4], &tmp_tr->color);
	ft_lstadd_tr(&conf->tr, tmp_tr);
}
