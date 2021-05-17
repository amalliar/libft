# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 23:55:29 by amalliar          #+#    #+#              #
#    Updated: 2021/05/18 01:47:46 by amalliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL      := /bin/sh
CC         := clang
CFLAGS     := -Wall -Wextra -fdiagnostics-color=auto -g -pipe \
              -march=native -O2 -fno-strict-aliasing
MAKEFLAGS  := -j 4 --output-sync=recurse --no-print-directory

# Protect against make incorrectly setting 'last modified' attribute 
# when running in parallel (-j flag).
POST_COMPILE = mv -f $(DEPDIR)/$*.tmp $(DEPDIR)/$*.d && touch $@

# Define some colors for printf.
BLACK      := \033[1;30m
RED        := \033[1;31m
GREEN      := \033[1;32m
YELLOW     := \033[1;33m
BLUE       := \033[1;34m
MAGENTA    := \033[1;35m
CYAN       := \033[1;36m
WHITE      := \033[1;37m
NOCOLOR    := \033[0m

INCLUDE    := -I./include -I../include -I../include/ft_printf
LIB        := -L.. -lft
LIBFT      := ../libft.a
NAME       := test
OBJDIR     := .obj
DEPDIR     := .dep

TSUITE     := tsuite_ft_ctype.c \
              tsuite_main.c

TUTILITY   := print_tbatch_header.c \
              print_tsuite_header.c
TUTILITY   := $(addprefix tutility/, $(TUTILITY))

SRCS       := $(TSUITE) $(TUTILITY)
OBJS       := $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS       := $(SRCS:%.c=$(DEPDIR)/%.d)

PREBUILD_MSG = "$(GREEN)==>$(WHITE) Creating target $(NAME)...$(NOCOLOR)\n"
PRECOMPILE_MSG = "  $(BLUE)->$(NOCOLOR) Compiling source files...\n"

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	@printf $(PREBUILD_MSG)
	@printf "  $(BLUE)->$(NOCOLOR) Linking executable...\n"
	$(CC) $(CFLAGS) $^ $(LIB) -o $@
	@printf "$(GREEN)==>$(WHITE) Finished making: $(NAME)\n"
.PHONY: all

$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	@printf $(PREBUILD_MSG)
	@printf $(PRECOMPILE_MSG)
	@$(eval PREBUILD_MSG="")
	@$(eval PRECOMPILE_MSG="")
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -MF $(DEPDIR)/$*.tmp -c -o $@ $<
	@$(POST_COMPILE)

$(OBJDIR):
	@mkdir -p $(OBJDIR)/tutility

$(DEPDIR):
	@mkdir -p $(DEPDIR)/tutility

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

$(LIBFT):
	@$(MAKE) -C .. MAKEFLAGS=

clean:
	@printf "$(GREEN)==>$(WHITE) Tidying install...$(NOCOLOR)\n"
	@printf "  $(BLUE)->$(NOCOLOR) Removing object files...\n"
	@-rm -rf $(OBJDIR)
	@printf "  $(BLUE)->$(NOCOLOR) Removing make dependency files...\n"
	@-rm -rf $(DEPDIR)
.PHONY: clean

fclean: clean
	@printf "  $(BLUE)->$(NOCOLOR) Removing executable...\n"
	@-rm -f $(NAME)
.PHONY: fclean

re:
	@$(MAKE) fclean MAKEFLAGS=
	@$(MAKE) all MAKEFLAGS=
.PHONY: re

help:
	@printf "The following are some of the valid targets for this Makefile:\n"
	@printf "... all (the default if no target is provided)\n"
	@printf "... clean\n"
	@printf "... fclean\n"
	@printf "... re\n"
.PHONY: help

# Do not include dependency files if the current goal is
# set to clean/fclean/re.
ifeq ($(findstring $(MAKECMDGOALS), clean fclean re),)
    -include $(DEPS)
endif
