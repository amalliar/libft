# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 23:55:29 by amalliar          #+#    #+#              #
#    Updated: 2020/05/06 19:20:48 by amalliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/sh
CC := gcc
CFLAGS := -Wall -Wextra -Werror -fdiagnostics-color -g -pipe \
	-march=native -O2 -flto -I.
AR := ar -rcs
NAME := libft.a
NAMESO := libft.so

OBJDIR := .
SRCDIR := .
DEPDIR := $(OBJDIR)/.dep

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS := $(SRCS:$(SRCDIR)/%.c=$(DEPDIR)/%.d)

# Protect against make incorrectly setting 'last modified'
# attribute when running in parallel (-j flag).
POST_COMPILE = mv -f $(DEPDIR)/$*.tmp $(DEPDIR)/$*.d && touch $@

.DELETE_ON_ERROR:

.PHONY: all
all: $(NAME)

.PHONY: so
so: CFLAGS += -fpic
so: $(NAMESO)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(NAMESO): $(OBJS)
	$(CC) -shared -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPDIR)/%.d | $(DEPDIR)
	$(CC) $(CFLAGS) -MMD -MF $(DEPDIR)/$*.tmp -c $< -o $@
	@$(POST_COMPILE)

$(DEPDIR)/%.d: ;

$(DEPDIR): ; @mkdir -p $@

.PHONY: clean
clean:
	-rm -rf $(DEPDIR)
	-rm -rf $(OBJS)

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
    -include $(DEPS)
endif
