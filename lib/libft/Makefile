# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 19:57:59 by pruiz-ca          #+#    #+#              #
#    Updated: 2021/04/18 14:01:46 by pruiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

SRCS			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
					ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
					ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
					ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
					ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					ft_lstiter.c ft_lstmap.c ft_get_max.c ft_get_min.c\
					ft_strupper.c ft_strdup_limit.c ft_itoa_base.c \
					ft_itoa_base_llu.c ft_itoa_base_uint.c \
					get_next_line.c ft_isspace.c ft_split_isspace.c \
					ft_atof.c ft_power.c ft_freetab.c ft_ternary.c \
					ft_vecsum.c ft_vecsub.c ft_vecdot.c ft_veclen.c \
					ft_vecsca.c ft_degtorad.c ft_vecnorm.c ft_vecx.c \
					ft_vecxmat.c ft_vecscasub.c ft_swap_double.c \
					ft_vecscadiv.c ft_vcolorsum.c

OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-Wall -Wextra -Werror

HEADER			=	libft.h

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

%.o: %.c		$(HEADER)
				@gcc $(CFLAGS) -include $(HEADER) -o $@ -c $<

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
