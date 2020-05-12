# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 23:55:29 by amalliar          #+#    #+#              #
#    Updated: 2020/05/13 01:51:49 by amalliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL  := /bin/sh
CC     := clang
CFLAGS := -Wall -Wextra -Werror -fdiagnostics-color -g -pipe \
          -march=native -O2 -I.
AR     := ar -rcs
NAME   := libft.a
NAMESO := libft.so
BONUS  := .git/.bonus
DEPDIR := .git/.dep

SRCM   := ft_split.c \
          ft_itoa.c \
          ft_strchr.c \
          ft_strdup.c \
          ft_strjoin.c \
          ft_strmapi.c \
          ft_strnstr.c \
          ft_strrchr.c \
          ft_strtrim.c \
          ft_substr.c \
          ft_atoi.c \
          ft_isalnum.c \
          ft_isalpha.c \
          ft_isascii.c \
          ft_isdigit.c \
          ft_isprint.c \
          ft_memcmp.c \
          ft_strncmp.c \
          ft_tolower.c \
          ft_toupper.c \
          ft_strlcat.c \
          ft_strlcpy.c \
          ft_strlen.c \
          ft_calloc.c \
          ft_memccpy.c \
          ft_memchr.c \
          ft_memcpy.c \
          ft_memmove.c \
          ft_memset.c \
          ft_bzero.c \
          ft_putchar_fd.c \
          ft_putendl_fd.c \
          ft_putnbr_fd.c \
          ft_putstr_fd.c
SRCB   := ft_lstsize.c \
          ft_lstlast.c \
          ft_lstmap.c \
          ft_lstnew.c \
          ft_lstadd_back.c \
          ft_lstadd_front.c \
          ft_lstclear.c \
          ft_lstdelone.c \
          ft_lstiter.c
OBJM   := $(SRCM:%.c=%.o)
OBJB   := $(SRCB:%.c=%.o)
DEPM   := $(OBJM:%.o=%.d)
DEPB   := $(OBJM:%.o=%.d)

# Run multiple threads.
MAKEFLAGS    = -j 4 --output-sync=recurse --no-print-directory

# Protect against make incorrectly setting 'last modified'
# attribute when running in parallel (-j flag).
POST_COMPILE = mv -f $(DEPDIR)/$*.tmp $(DEPDIR)/$*.d && touch $@

# Define some colors for echo:
LGREEN := \033[1;32m
WHITE  := \033[1;37m
NOC    := \033[0m

.DELETE_ON_ERROR:

all: $(NAME)
$(NAME): $(OBJM)
	@echo -e "$(LGREEN)Linking C static library $(NAME)$(NOC)"
	@$(AR) $@ $^
	@echo "Built target $(NAME)"
.PHONY: all

bonus: $(BONUS)
$(BONUS): $(OBJM) $(OBJB)
	@echo -e "$(LGREEN)Linking C static library $(NAME)$(NOC)"
	@$(AR) $(NAME) $^
	@echo "Built target $(NAME)"
	@touch $(BONUS)
.PHONY: bonus

so: CFLAGS += -fpic
so: $(NAMESO)
$(NAMESO): $(OBJM) $(OBJB)
	@echo -e "$(LGREEN)Linking C dynamic library $(NAMESO)$(NOC)"
	@$(CC) -shared -o $@ $^
	@echo "Built target $(NAMESO)"
.PHONY: so

%.o: %.c $(DEPDIR)/%.d | $(DEPDIR)
	$(CC) $(CFLAGS) -MMD -MF $(DEPDIR)/$*.tmp -c -o $@ $<
	@$(POST_COMPILE)
$(DEPDIR)/%.d: ;
$(DEPDIR): ; @mkdir -p $@

clean:
	@echo -e "$(WHITE)Removing C object files...$(NOC)"
	@-rm -f $(OBJM) $(OBJB)
	@echo -e "$(WHITE)Removing make dependency files...$(NOC)"
	@-rm -rf $(DEPDIR)
	@-rm -f $(BONUS)
.PHONY: clean

fclean: clean
	@echo -e "$(WHITE)Removing C static library $(NAME)$(NOC)"
	@-rm -f $(NAME)
	@echo -e "$(WHITE)Removing C dynamic library $(NAMESO)$(NOC)"
	@-rm -f $(NAMESO)
.PHONY: fclean

re:
	$(MAKE) fclean MAKEFLAGS=
	$(MAKE) all MAKEFLAGS=
.PHONY: re

help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... bonus"
	@echo "... so"
	@echo "... clean"
	@echo "... fclean"
	@echo "... re"
.PHONY: help

# Do not include .d files if the current goal is set to
# clean/fclean/re.
ifeq ($(findstring $(MAKECMDGOALS), clean fclean re),)
    -include $(DEPM)
    -include $(DEPB)
endif
