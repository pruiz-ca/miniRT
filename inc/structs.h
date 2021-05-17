/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 17:13:04 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 14:46:24 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdio.h>
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"

typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bpp;
	int					ll;
	int					endian;
}						t_img;

typedef struct s_res
{
	int					x;
	int					y;
	double				ratio;
	int					enabled;
}						t_res;

typedef struct s_amb
{
	t_color				color;
	double				bright;
	int					enabled;
}						t_amb;

typedef struct s_cam
{
	t_vector			pos;
	t_vector			dir;
	int					fov;
	double				fov_w;
	struct s_cam		*next;
	struct s_cam		*first;
	t_vector			pxldir_gen;
	t_vector			mat[4];
}						t_cam;

typedef struct s_light
{
	t_vector			pos;
	t_color				color;
	double				bright;
	struct s_light		*next;
}						t_light;

typedef struct s_sp
{
	t_vector			pos;
	t_color				color;
	double				radius;
	double				ans1;
	double				ans2;
	double				t;
	struct s_sp			*next;
}						t_sp;

typedef struct s_pl
{
	t_vector			pos;
	t_vector			dir;
	t_color				color;
	struct s_pl			*next;
}						t_pl;

typedef struct s_sq
{
	t_vector			pos;
	t_vector			dir;
	t_color				color;
	double				side;
	double				xmin;
	double				xmax;
	double				ymin;
	double				ymax;
	struct s_sq			*next;
}						t_sq;

typedef struct s_cy
{
	t_vector			pos;
	t_vector			dir;
	t_color				color;
	double				radius;
	double				height;
	struct s_cy			*next;
}						t_cy;

typedef struct s_tr
{
	t_vector			pos1;
	t_vector			pos2;
	t_vector			pos3;
	t_color				color;
	struct s_tr			*next;
}						t_tr;

typedef struct s_pxl
{
	double				t;
	t_color				color;
	t_color				lcolor;
	t_vector			hitpnt;
	t_vector			acnepnt;
	t_vector			objpos;
	t_vector			normal;
	t_vector			dir;
}						t_pxl;

typedef struct s_movelist
{
	int					is_triangle;
	t_vector			*pos1;
	t_vector			*pos2;
	t_vector			*pos3;
}						t_movelist;

typedef struct s_sc
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_res				res;
	t_amb				amb;
	t_cam				first_cam;
	t_cam				*cam;
	t_light				*light;
	t_pl				*pl;
	t_sp				*sp;
	t_sq				*sq;
	t_cy				*cy;
	t_tr				*tr;
	t_pxl				pxl;
	t_movelist			movelist;
	int					filter;
	int					screenshot;
}						t_sc;

typedef struct s_intersect
{
	float				a;
	float				b;
	float				c;
	float				discr;
	t_vector			edge1;
	t_vector			edge2;
	t_vector			tvec;
	t_vector			pvec;
	t_vector			qvec;
	t_vector			ans;
	t_vector			cy_a;
	t_vector			cy_b;
	t_vector			cy_p;
	double				det;
	double				det_inv;
	int					is_valid;
	double				a1;
	double				a2;
}						t_intersect;

typedef struct s_bmp
{
	char				bitmapSignatureBytes[2];
	unsigned int		sizeOfBitmapFile;
	int					reservedBytes;
	unsigned int		pixelDataOffset;
	unsigned int		sizeOfThisHeader;
	int					width;
	int					height;
	short				numberOfColorPlanes;
	short				colorDepth;
	unsigned int		compressionMethod;
	unsigned int		rawBitmapDataSize;
	int					horizontalResolution;
	int					verticalResolution;
	unsigned int		colorTableEntries;
	unsigned int		importantColors;
} __attribute__((packed, aligned(1)))
t_bmp;

typedef struct s_thread
{
	t_sc				sc;
	int					start;
	int					end;
}						t_thread;

#endif
