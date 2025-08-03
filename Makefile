NAME = fdf

BUILD = ./build

SRC = ./src

SRCS = ./src/fdf.c \
		./src/draw.c \
		./src/colours.c \
		./src/fdf_init.c \
		./src/fdf_parse.c \
		./src/fdf_utils.c \
		./src/ft_printf.c \
		./src/fdf_events.c \
		./src/fdf_control.c \
		./src/fdf_functions.c \
		./src/ft_printf_lib.c \
		./src/fdf_validation.c

OBJS = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

CFLAGS = -Wall -Wextra -Werror

HEADER = includes/fdf.h includes/ft_printf.h

MINILIBX = lib/minilibx_macos

FMS = -framework OpenGL -framework AppKit -L $(MINILIBX) -lmlx

ifeq ($(shell uname -s), Linux)
	MINILIBX = lib/minilibx-linux
	FMS = -L $(MINILIBX) -lmlx -lm -lX11 -lXext
endif

INCS = -Iincludes -I$(MINILIBX)

RESET			= \033[0m
PURPLE			= \033[0;35m
LIGHT_PURPLE	= \033[1;35m

$(BUILD)/%.o:	$(SRC)/%.c $(HEADER) Makefile
	@printf "${PURPLE}✧ ${RESET}";
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all:	$(BUILD) mlx ${NAME}

${NAME}: ${OBJS}
	@$(CC) $(CFLAGS) $(OBJS) $(INCS) $(FMS) -o ${NAME}
	@echo
	@echo "${LIGHT_PURPLE}FDF created 👾${RESET}"
	@echo "$(PURPLE)------------------------------------------------------------------$(RESET)"
	@echo "$(PURPLE)| Usage               | ./fdf <path/to/map.rt>                   |$(RESET)"
	@echo "$(PURPLE)------------------------------------------------------------------$(RESET)"
	@echo "$(PURPLE)| Recommended Maps    | maps/MGDS_WHOLE_WORLD_OCEAN0_*.fdf       |$(RESET)"
	@echo "$(PURPLE)| Recommended Maps    | maps/MGDS_WHOLE_WORLD_OCEAN1_*.fdf       |$(RESET)"
	@echo "$(PURPLE)|                     | maps/France.XXL.fdf                      |$(RESET)"
	@echo "$(PURPLE)|                     | maps/fract.fdf                           |$(RESET)"
	@echo "$(PURPLE)|                     | maps/japan.fdf                           |$(RESET)"
	@echo "$(PURPLE)|                     | maps/julia.fdf                           |$(RESET)"
	@echo "$(PURPLE)|                     | maps/USGS_ULCN2005_grid.txt_OCEAN1_L.fdf |$(RESET)"
	@echo "$(PURPLE)------------------------------------------------------------------$(RESET)"
	@echo "$(PURPLE)| Help                | make help                                |$(RESET)"
	@echo "$(PURPLE)------------------------------------------------------------------$(RESET)"

$(BUILD):
	@mkdir -p $(BUILD)

mlx:
	@echo "${LIGHT_PURPLE}Compiling MiniLibX ${RESET}"
	@make -C $(MINILIBX) > /dev/null 2>&1 & i=0; \
	while ps -p $$! > /dev/null; do \
		printf "${PURPLE}✧ ${RESET}"; \
		sleep 0.3; \
	done
	@echo
	@echo "${LIGHT_PURPLE}Done ✔️${RESET}"

clean:
	@rm -rf $(BUILD)
	@make clean -C $(MINILIBX) > /dev/null 2>&1 & i=0
	@echo "${PURPLE}Everything is clear 👾${RESET}"

fclean:	clean
	@rm -rf ${NAME}

re:		fclean all

help:
	@echo "$(PURPLE)------------------------------------------------------------------$(RESET)"
	@echo "$(PURPLE)| Controls      | ⬆     - Lift up                                |$(RESET)"
	@echo "$(PURPLE)|               | ⬇     - Дip down                               |$(RESET)"
	@echo "$(PURPLE)|               | ⬅     - Take it left                           |$(RESET)"
	@echo "$(PURPLE)|               | ➡     - Take it right                          |$(RESET)"
	@echo "$(PURPLE)|               | +     - Zoom in                                |$(RESET)"
	@echo "$(PURPLE)|               | -     - Zoom out                               |$(RESET)"
	@echo "$(PURPLE)|               | A     - Rotate to the left                     |$(RESET)"
	@echo "$(PURPLE)|               | D     - Rotate to the right                    |$(RESET)"
	@echo "$(PURPLE)|               | W     - Increase z coordinate                  |$(RESET)"
	@echo "$(PURPLE)|               | S     - Decrease z coordinate                  |$(RESET)"
	@echo "$(PURPLE)|               | I     - Isometriv view                         |$(RESET)"
	@echo "$(PURPLE)|               | T     - Top view                               |$(RESET)"
	@echo "$(PURPLE)|               | P     - Side view                              |$(RESET)"
	@echo "$(PURPLE)------------------------------------------------------------------$(RESET)"

.PHONY: all clean fclean mlx help re
