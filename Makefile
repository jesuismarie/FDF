NAME = fdf

SRCS = ./src/fdf.c ./src/draw.c ./src/fdf_error.c ./src/fdf_functions.c ./src/fdf_parse.c \
		./src/fdf_utils.c ./src/ft_printf_lib.c ./src/ft_printf.c ./src/fdf_control.c

OBJS = ${SRCS:.c=.o}

INCS = -I

CFLAGS = -Wall -Wextra -Werror

HEADER = ./includes/fdf.h

MINILIBX = minilibx_macos

FMS = -framework OpenGL -framework AppKit -L $(MINILIBX) -lmlx

ifeq ($(shell uname -s), Linux)
	MINILIBX = minilibx-linux
	FMS= -L $(MINILIBX) -lmlx -lm -lX11 -lXext
endif

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCS)$(MINILIBX) -c $< -o $@

all:	mlx ${NAME}

mlx:
	make -C $(MINILIBX)

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) $(FMS) -o ${NAME}

clean:
	rm -f $(OBJS)
	make clean -C $(MINILIBX)

fclean: clean
	rm -f ${NAME}

re: 	fclean all

.PHONY: all clean fclean mlx
