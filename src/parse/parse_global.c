/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:39:08 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 18:06:17 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_hub(char **tab, t_sc *conf, int n_words)
{
	if (!tab[0])
		return ;
	if (ft_strncmp(tab[0], "R", 3) == 0)
		parse_res(tab, conf, n_words);
	else if (ft_strncmp(tab[0], "A", 3) == 0)
		parse_amb(tab, conf, n_words);
	else if (ft_strncmp(tab[0], "c", 3) == 0)
		parse_cam(tab, conf, n_words);
	else if (ft_strncmp(tab[0], "l", 3) == 0)
		parse_light(tab, conf, n_words);
	else if (ft_strncmp(tab[0], "pl", 3) == 0)
		parse_pl(tab, conf, n_words);
	else if (ft_strncmp(tab[0], "sp", 3) == 0)
		parse_sp(tab, conf, n_words);
	else if (ft_strncmp(tab[0], "sq", 3) == 0)
		parse_sq(tab, conf, n_words);
	else if (ft_strncmp(tab[0], "cy", 3) == 0)
		parse_cy(tab, conf, n_words);
	else if (ft_strncmp(tab[0], "tr", 3) == 0)
		parse_tr(tab, conf, n_words);
	else if (ft_strncmp(tab[0], "#", 3) == 0)
		return ;
	else
		errors(-1);
}

void	parse_file(int fd, t_sc *conf)
{
	char	*line;
	char	**tab;
	int		n_words;
	int		b;

	b = get_next_line(fd, &line);
	while (b > 0)
	{
		tab = ft_split_isspace(line, &n_words);
		parse_hub(tab, conf, n_words);
		free(line);
		ft_freetab(tab);
		b = get_next_line(fd, &line);
	}
	if (b < 0)
		errors(-8);
	free(line);
}

char	*get_map(t_sc *sc, int argc, char *a1, char *a2)
{
	char	*map_path;

	map_path = NULL;
	if (a1 && a2 && !ft_strncmp(a2, "--save", 7) && argc == 3)
	{
		map_path = a1;
		sc->screenshot = 1;
	}
	else if (a1 && ft_strncmp(a1, "--save", 7) && argc == 2)
		map_path = a1;
	else
		errors(-8);
	return (map_path);
}
