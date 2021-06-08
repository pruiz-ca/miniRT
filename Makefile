# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 14:07:20 by pruiz-ca          #+#    #+#              #
#    Updated: 2021/05/17 17:10:13 by pruiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

RT	=	scenes/test

S	=	src/
P	=	parse/
R	=	render/
O	=	obj/
I	=	inc/
C	=	controls/
U	=	utils/

SRCS	=	$Smain.c $S$Ubmp.c $S$Uerrors.c $S$Uutils.c \
		$S$Pparse_global.c $S$Pparse_scene.c $S$Pparse_light.c \
		$S$Pparse_cam.c $S$Pparse_pl.c $S$Pparse_sq.c $S$Pparse_sp.c \
		$S$Pparse_cy.c $S$Pparse_tr.c \
		$S$Rrender_global.c $S$Rrender_sp.c $S$Rrender_pl.c \
		$S$Rrender_sq.c \
		$S$Rrender_cams.c $S$Rrender_lights.c $S$Rfilters.c \
		$S$Rrender_tr.c $S$Rrender_cy.c $S$Rmultithreading.c \
		$S$Ckeys.c $S$Ccam_movement.c $S$Ccam_rotation.c \
		$S$Cobj_movement.c $S$Cobj_cycle.c
OBJS	=	$(SRCS:$S%.c=$O%.o)

HEADER	=	-include $Istructs.h -include $Iminirt.h -include $Ikeycodes.h

CC	=	gcc

EXTRA	=	-march=skylake -pthread

FLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS) $()
		@make -C lib/libft
		@make -C lib/minilibx > /dev/null 2>&1
		@$(CC) $(EXTRA) $(FLAGS) $(SRCS) $(HEADER) -L lib/libft -lft -L lib/minilibx -lmlx -lpthread -framework OpenGL -framework AppKit -o $(NAME)

$O%.o: 		$S%.c
		@[ -d $(O) ] || mkdir -p $(O)
		@[ -d $(O)$(C) ] || mkdir -p $(O)$(C)
		@[ -d $(O)$(P) ] || mkdir -p $(O)$(P)
		@[ -d $(O)$(R) ] || mkdir -p $(O)$(R)
		@[ -d $(O)$(U) ] || mkdir -p $(O)$(U)
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(O)
		@make clean -C lib/libft
		@make clean -C lib/minilibx

fclean:		clean
		@rm -f $(NAME)
		@rm -f lib/libft/libft.a
		@rm -f lib/minilibx/libmlx.a
		@rm -f screenshot.bmp

re:		fclean all

run:		re
		@make clean
		./miniRT $(RT).rt

norm:
		@norminette lib/libft/*.h inc/*.h
		@norminette lib/libft/*.c src/*.c src/parse/*.c src/render/*.c
		@norminette src/utils/*.c src/bonus/*.c

.PHONY:		all clean fclean re run git norm
