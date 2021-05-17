/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:25:20 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/03/11 18:57:49 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_lstadd_sp(t_sp **lst, t_sp *new)
{
	t_sp	*tmp;

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

void	parse_sp(char **tab, t_sc *conf, int n_words)
{
	t_sp	*sp;

	if (n_words != 4)
		errors(-1);
	check_str(tab[1], 1, 1, 1);
	check_str(tab[2], 1, 1, 0);
	check_str(tab[3], 0, 0, 1);
	sp = malloc(sizeof(t_sp));
	if (!sp)
		errors(-1);
	sp->next = NULL;
	get_vector(tab[1], &sp->pos, 0);
	sp->radius = ft_atof(tab[2]) / 2;
	get_color(tab[3], &sp->color);
	ft_lstadd_sp(&conf->sp, sp);
}
