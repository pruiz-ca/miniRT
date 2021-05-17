/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:39:13 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/19 16:15:06 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include "structs.h"
# include "keycodes.h"
# include "../lib/libft/libft.h"

# define EPSILON 0.0001f
# define MAXTHREADS 6
# define MOV_STEP 15

/* PARSING */
char	*get_map(t_sc *sc, int argc, char *a1, char *a2);
void	parse_file(int fd, t_sc *conf);
void	parse_res(char **tab, t_sc *conf, int n_words);
void	parse_amb(char **tab, t_sc *conf, int n_words);
void	parse_cam(char **tab, t_sc *conf, int n_words);
void	parse_light(char **tab, t_sc *conf, int n_words);
void	parse_tr(char **tab, t_sc *conf, int n_words);
void	parse_sq(char **tab, t_sc *conf, int n_words);
void	parse_sp(char **tab, t_sc *conf, int n_words);
void	parse_pl(char **tab, t_sc *conf, int n_words);
void	parse_cy(char **tab, t_sc *conf, int n_words);

/* UTILS */
void	get_color(char *tab, t_color *color);
void	get_vector(char *tab, t_vector *vector, int isnormalized);
void	my_mlx_pixel_put(t_sc *conf, int x, int y, int color);
int		exit_minirt(t_sc *sc);
int		quad(t_intersect *eq, double *ans1, double *ans2);
int		quad_isvalid(double *ans1, double *ans2);
int		quad_cy(t_intersect *eq, t_vector from, t_vector dir, t_cy *cy);
void	get_pixldir(t_sc *conf, double posx, double posy);
void	check_collision(t_sc *conf);

/* ERRORS */
void	errors(int numerror);
void	check_str(char *str, int neg, int dot, int comma);
void	check_range(int value, int min, int max);

/* RENDER */
void	render(t_sc *conf, t_img *img);
void	get_intersection(t_sc *conf);
void	transf_cam(t_cam *cam);
void	render_cams(t_sc *conf);
void	ray_sp(t_sp *sp, t_pxl *pxl, t_vector dir, t_vector from);
void	ray_pl(t_pl *pl, t_pxl *pxl, t_vector dir, t_vector from);
void	ray_tr(t_tr *tr, t_pxl *pxl, t_vector dir, t_vector from);
void	ray_sq(t_sq *sq, t_pxl *pxl, t_vector dir, t_vector from);
void	ray_cy(t_cy *cy, t_pxl *pxl, t_vector dir, t_vector from);
void	render_lights(t_sc *conf, t_light *light, t_pxl *pxl);
void	filter_hub(t_color *color, int filtervalue);

/* BMP */
void	bmp_create(t_sc *conf);
void	transf_matrix(t_cam *cam);
void	get_pxldir_gen(t_sc *conf, t_cam *cam);

/* MULTITHREADING */
void	multithread(t_sc *sc);
void	render_cams_mt(t_thread *conf);
void	render_mt(t_sc *sc, t_img *img);

/* KEYS */
int		key_press(int keycode, t_sc *sc);
int		mouse_press(int keycode, int x, int y, t_sc *sc);
void	obj_movement_hub(int keycode, t_sc *sc);
void	cam_cycle(int keycode, t_sc *sc);
void	cam_movement(int keycode, t_sc *sc);
void	cam_rotation(int keycode, t_sc *sc);
void	cam_filter(int keycode, t_sc *sc);
void	rotate_x(t_sc *sc, t_vector *dir, int sign);
void	rotate_y(t_sc *sc, t_vector *dir, int sign);
int		sp_cycle(t_sc *sc, t_movelist *current_obj, int *idx, int *tmp_idx);
int		pl_cycle(t_sc *sc, t_movelist *current_obj, int *idx, int *tmp_idx);
int		cy_cycle(t_sc *sc, t_movelist *current_obj, int *idx, int *tmp_idx);
int		sq_cycle(t_sc *sc, t_movelist *current_obj, int *idx, int *tmp_idx);
int		tr_cycle(t_sc *sc, t_movelist *current_obj, int *idx, int *tmp_idx);

#endif
