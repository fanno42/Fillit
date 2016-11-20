# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fanno <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/23 16:40:31 by fanno             #+#    #+#              #
#    Updated: 2016/03/07 10:42:08 by fanno            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a
LIB_LINK = -L $(LIB_PATH) -lft

INC_DIR = includes
INCS = -I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)

SRC_DIR = src
SRC_BASE = ft_check_ir0.c \
		   ft_check_ir90.c \
		   ft_check_jr0.c \
		   ft_check_jr180.c \
		   ft_check_jr270.c \
		   ft_check_jr90.c \
		   ft_check_lr0.c \
		   ft_check_lr180.c \
		   ft_check_lr270.c \
		   ft_check_lr90.c \
		   ft_check_or0.c \
		   ft_check_sr0.c \
		   ft_check_sr90.c \
		   ft_check_tiles.c \
		   ft_check_tr0.c \
		   ft_check_tr180.c \
		   ft_check_tr270.c \
		   ft_check_tr90.c \
		   ft_check_zr0.c \
		   ft_check_zr90.c \
		   ft_get_file.c \
		   ft_get_struct.c \
		   ft_print_grid.c \
		   ft_solve.c \
		   ft_solve_2.c \
		   ft_split_file_content.c \
		   ft_strstr_binary.c \
		   main.c

OBJ_DIR = obj

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_BASE))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_BASE:.c=.o))

C_NO = "\033[00m"
C_OK = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

SUCCES = $(C_GOOD)SUCCES$(C_NO)
OK = $(C_OK)OK$(C_NO)

all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
		@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)
		@echo "Compiling" [ $(NAME) ] $(SUCCES)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
		@$(CC) $(FLAGS) $(INCS) -c -o $@ $<
		@echo "Linking" [ $< ] $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: clean all re fclean
