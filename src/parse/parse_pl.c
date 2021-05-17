/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:25:11 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/03/12 20:01:13 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_lstadd_pl(t_pl **lst, t_pl *new)
{
	t_pl	*tmp;

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

void	parse_pl(char **tab, t_sc *conf, int n_words)
{
	t_pl	*tmp_pl;

	if (n_words != 4)
		errors(-1);
	check_str(tab[1], 1, 1, 1);
	check_str(tab[2], 1, 1, 1);
	check_str(tab[3], 0, 0, 1);
	tmp_pl = malloc(sizeof(t_pl));
	tmp_pl->next = NULL;
	get_vector(tab[1], &tmp_pl->pos, 0);
	get_vector(tab[2], &tmp_pl->dir, 1);
	tmp_pl->dir = ft_vecsca(tmp_pl->dir, -1);
	get_color(tab[3], &tmp_pl->color);
	ft_lstadd_pl(&conf->pl, tmp_pl);
}
