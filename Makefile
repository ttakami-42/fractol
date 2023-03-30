# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 15:46:07 by ttakami           #+#    #+#              #
#    Updated: 2023/03/31 06:28:57 by ttakami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
DEBUG		= -g -fsanitize=address -fsanitize=undefined
LEAK		= -g -fsanitize=leak
SRCS		=   main.c \
				utils.c \
				validate_args.c \
				init_fractol.c \
				pixel_put.c \
				draw_fractol.c \
				hooks.c \
				set_mlx_hooks.c
OBJDIR		= obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFTDIR	= libft
LIBFT		= -lft
MLXDIR		= minilibx-linux
INC			= -Iinclude -I$(LIBFTDIR) -I$(MLXDIR)

UNAME 		= $(shell uname -s)

ifeq ($(UNAME), Darwin)
	INC		+= -I/usr/X11/include
	MLX		=-lmlx_Darwin
	MLXFLAG	= -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit -L$(MLXDIR)
else
	MLX		= -lmlx
	MLXFLAG	= -L/usr/lib -lXext -lX11 -lm -L$(MLXDIR)
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
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(LIBFT):
	@make bonus --no-print-directory -sC $(LIBFTDIR)

$(MLX):
	@make --no-print-directory -C $(MLXDIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) $(LIBFT) $(MLXFLAG) $(MLX)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -rf $(OBJDIR)
	@make clean --no-print-directory -sC $(LIBFTDIR)
	@echo "done\n"

fclean: clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)
	@make fclean --no-print-directory -sC $(LIBFTDIR)
	@echo "done\n"

re: fclean all

debug: $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG) -o $(NAME) $(OBJS) -L$(LIBFTDIR) $(LIBFT)
	@echo "$(GREEN)***   You can debug $(NAME)   ...   ***\n$(RESET)"

leak: $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(LEAK) -o $(NAME) $(OBJS) -L$(LIBFTDIR) $(LIBFT)
	@echo "$(GREEN)***   You can see leaks $(NAME)   ...   ***\n$(RESET)"

.PHONY:	all clean fclean re debug leak

vpath %.c src
