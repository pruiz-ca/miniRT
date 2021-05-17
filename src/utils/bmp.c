/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:12:00 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/16 16:17:03 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	bmp_init(t_bmp *bmp, t_sc *sc)
{
	bmp->bitmapSignatureBytes[0] = 'B';
	bmp->bitmapSignatureBytes[1] = 'M';
	bmp->sizeOfBitmapFile = 0;
	bmp->reservedBytes = 0;
	bmp->pixelDataOffset = 54;
	bmp->sizeOfThisHeader = 40;
	bmp->width = sc->res.x;
	bmp->height = sc->res.y;
	bmp->numberOfColorPlanes = 1;
	bmp->colorDepth = 32;
	bmp->compressionMethod = 0;
	bmp->rawBitmapDataSize = 0;
	bmp->horizontalResolution = 0;
	bmp->verticalResolution = 0;
	bmp->colorTableEntries = 0;
	bmp->importantColors = 0;
}

void	bmp_create(t_sc *sc)
{
	int		i;
	int		fd;
	int		pad;
	t_bmp	bmp;

	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	if (fd < 0)
		errors(-7);
	i = sc->res.y;
	pad = (4 - (sc->res.x * 3) % 4) % 4;
	bmp_init(&bmp, sc);
	write(fd, &bmp, 54);
	while (i-- > 0)
	{
		write(fd, &sc->img.addr[i * sc->img.ll], sc->res.x * sc->img.bpp / 8);
		write(fd, &(t_vector){0, 0, 0}, pad);
	}
	close(fd);
	exit(0);
}
