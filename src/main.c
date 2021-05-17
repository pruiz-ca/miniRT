/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:46:58 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/05/17 17:09:59 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	int			fd;
	char		*map_path;
	t_sc		sc;

	if (argc < 2 || argc > 3)
		errors(-8);
	ft_bzero(&sc, sizeof(t_sc));
	map_path = get_map(&sc, argc, argv[1], argv[2]);
	fd = open(map_path, O_RDONLY);
	parse_file(fd, &sc);
	if (!sc.res.enabled || !sc.amb.enabled)
		errors(-1);
	if (!sc.cam)
		errors(-1);
	sc.first_cam = *sc.cam;
	render_mt(&sc, &sc.img);
	multithread(&sc);
	mlx_loop(sc.mlx);
	close(fd);
}
