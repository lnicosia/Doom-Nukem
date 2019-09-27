# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2019/09/27 09:26:25 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MAKEFILE = Makefile

SRC_DIR = .
OBJ_DIR = obj
INCLUDES_DIR = .
BIN_DIR = .
PRINTF_DIR = ft_printf

SRC_RAW = ft_memccpy.c ft_memcpy.c ft_memset.c ft_bzero.c ft_memmove.c \
		  ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c ft_isprint.c \
		  ft_putchar_fd.c ft_putchar.c ft_putstr.c ft_putstr_fd.c ft_strlen.c \
		  ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
		  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strrchr.c ft_strchr.c \
		  ft_strstr.c ft_strnstr.c ft_atoi.c ft_strcmp.c ft_strncmp.c \
		  ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
		  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		  ft_strmapi.c ft_strnequ.c ft_strequ.c ft_strsub.c ft_strjoin.c \
		  ft_strtrim.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
		  ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstlen.c ft_lstpushback.c \
		  ft_abs.c get_next_line.c ft_strjoin_free.c ft_min.c ft_max.c \
		  ft_fmin.c ft_fmax.c ft_count.c ft_fabs.c ft_atoi_base.c errors.c \
		  ft_clamp.c ft_fclamp.c ft_fclamp.c ft_atof.c ft_getlen.c \
		  ft_sitoa.c ft_realloc.c ft_getsize.c ft_delindex.c ft_perror.c \
		  ft_lstcontains.c vector_utils.c segments_intersect.c \
		  get_intersection.c

HEADERS = libft.h

PRINTF_SRC_RAW = ft_printf.c ft_dprintf.c base_utils.c parse_colors.c \
				 parse_flags.c parse_functions.c pf_atoi.c pf_float_padding.c \
				 pf_invalid.c pf_putaddr.c pf_putchar.c pf_putfloat.c \
				 pf_putlong_base.c pf_putnbr.c pf_putnbr_base.c \
				 pf_putpercent.c pf_putstr.c pf_putunbr.c pf_strnequ.c \
				 put_padding.c putfloat_utils.c

PRINTF_HEADERS = ft_printf.h base_utils.h color.h put_padding.h

SRC = $(addprefix $(SRC_DIR)/, $(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_RAW:.c=.o))
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

PRINTF_SRC = $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRC_RAW))
PRINTF_OBJ = $(addprefix $(OBJ_DIR)/, $(PRINTF_SRC_RAW:.c=.o))

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES_DIR) -I $(PRINTF_DIR) #-flto -O3

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"

all: $(BIN_DIR)/$(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@gcc -c $< -o $@ $(CFLAGS) 

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c $(PRINTF_DIR) $(MAKEFILE)
	@gcc -c $< -o $@ $(CFLAGS) 

$(BIN_DIR)/$(NAME): $(OBJ_DIR) $(OBJ) $(PRINTF_OBJ)
	@ar rc $(NAME) $(OBJ) $(PRINTF_OBJ)
	@ranlib $(NAME)
	@echo ${GREEN}"[INFO] Compiled '$(NAME)' with success"${RESET}

clean: 
	@rm -f $(OBJ)
	@rm -Rf $(OBJ_DIR)
	@echo ${CYAN}"[INFO] Removed objs from the libft"${RESET}

fclean: clean
	@rm -Rf $(NAME)
	@echo ${CYAN}"[INFO] Removed $(NAME) from the libft"${RESET}

re: fclean all

.PHONY: fclean all clean libft
