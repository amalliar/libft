# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 23:55:29 by amalliar          #+#    #+#              #
#    Updated: 2020/05/07 22:24:53 by amalliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL  := /bin/sh
CC     := gcc
CFLAGS := -Wall -Wextra -Werror -fdiagnostics-color -g -pipe \
          -march=native -O2 -flto -I.
AR     := ar -rcs
NAME   := libft.a
NAMESO := libft.so

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
SRCB   := ft_lstnew.c \
	  ft_lstadd_front.c \
	  ft_lstsize.c
OBJM   := $(SRCM:%.c=%.o)
OBJB   := $(SRCB:%.c=%.o)
DEPM   := $(OBJM:%.o=%.d)
DEPB   := $(OBJM:%.o=%.d)

# Protect against make incorrectly setting 'last modified'
# attribute when running in parallel (-j flag).
POST_COMPILE = mv -f $(DEPDIR)/$*.tmp $(DEPDIR)/$*.d && touch $@

.DELETE_ON_ERROR:

.PHONY: all
all: $(NAME)

$(NAME): $(OBJM)
	-rm -f $(NAME)
	$(AR) $@ $^

.PHONY: so
so: CFLAGS += -fpic
so: $(NAMESO)

$(NAMESO): $(OBJM) $(OBJB)
	$(CC) -shared -o $@ $^

.PHONY: bonus
bonus: $(NAME) $(OBJB)
	$(AR) $^


%.o: %.c $(DEPDIR)/%.d | $(DEPDIR)
	$(CC) $(CFLAGS) -MMD -MF $(DEPDIR)/$*.tmp -c -o $@ $<
	@$(POST_COMPILE)

$(DEPDIR)/%.d: ;

$(DEPDIR): ; @mkdir -p $@

.PHONY: clean
clean:
	-rm -rf $(DEPDIR)
	-rm -rf $(OBJM)
	-rm -rf $(OBJB)

.PHONY: fclean
fclean: clean
	-rm -f $(NAME)
	-rm -f $(NAMESO)

.PHONY: re
re: 
	@$(MAKE) fclean
	@$(MAKE) all

# Do not include .d files if the current goal is set to
# clean/fclean/re.
ifeq ($(findstring $(MAKECMDGOALS), clean fclean re),)
    -include $(DEPM)
    -include $(DEPB)
endif
