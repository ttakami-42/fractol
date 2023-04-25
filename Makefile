# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 15:46:07 by ttakami           #+#    #+#              #
#    Updated: 2023/04/26 02:18:29 by ttakami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra

ifdef WITH_DEBUG
	CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address -fsanitize=undefined
endif

ifdef WITH_LEAK
	CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=leak
endif

SRCS		=   main.c \
				utils.c \
				validate_args.c \
				init_fractol.c \
				pixel_put.c \
				complex.c \
				draw_fractol.c \
				hooks.c \
				zoom.c \
				pan.c \
				set_mlx_hooks.c

OBJDIR		= obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFTDIR	= libft
LIBFT		= $(addprefix $(LIBFTDIR)/, libft.a)
MLXDIR		= minilibx-linux
INC			= -Iinclude -I$(LIBFTDIR) -I$(MLXDIR)

UNAME 		= $(shell uname -s)

ifeq ($(UNAME), Darwin)
	EXTRA	= -I/usr/X11/include
	MLX		= $(addprefix $(MLXDIR)/, libmlx_Darwin.a)
	MLXFLAG	= -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
else
	EXTRA	= -O3
	MLX		= $(addprefix $(MLXDIR)/, libmlx.a)
	MLXFLAG	= -L/usr/lib -lXext -lX11 -lm
endif

# color codes
RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

# Check if object directory exists, build libft and then the Projects
all: $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@[ -d $(OBJDIR) ]
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	$(CC) $(CFLAGS) $(INC) $(EXTRA) -c -o $@ $<

$(LIBFT):
	@make bonus --no-print-directory -sC $(LIBFTDIR)

$(MLX):
	@make --no-print-directory -C $(MLXDIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAG)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -rf $(OBJDIR)
	@make clean --no-print-directory -sC $(LIBFTDIR)
	@make clean --no-print-directory -C $(MLXDIR)
	@echo "done\n"

fclean: clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)
	@make fclean --no-print-directory -sC $(LIBFTDIR)
	@echo "done\n"

re: fclean all

debug: fclean
	@make --no-print-directory WITH_DEBUG=1
	@echo "$(GREEN)***   You can debug $(NAME)   ***\n$(RESET)"

leak: fclean
	@make --no-print-directory WITH_LEAK=1
	@echo "$(GREEN)***   You can see leaks $(NAME)   ***\n$(RESET)"

.PHONY:	all clean fclean re debug leak

vpath %.c src
