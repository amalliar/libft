# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 23:55:29 by amalliar          #+#    #+#              #
#    Updated: 2021/05/18 09:07:59 by amalliar         ###   ########.fr        #
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

INCLUDE    := -I./include \
              -I./include/ft_printf
AR         := ar -rcs
NAME       := libft.a
NAMESO     := libft.so
OBJDIR     := .obj
DEPDIR     := .dep

FT_CTYPE   := ft_isalnum.c \
              ft_isalpha.c \
              ft_isblank.c \
              ft_iscntrl.c \
              ft_isdigit.c \
              ft_isgraph.c \
              ft_islower.c \
              ft_isprint.c \
              ft_ispunct.c \
              ft_isspace.c \
              ft_isupper.c \
              ft_isxdigit.c \
              ft_tolower.c \
              ft_toupper.c
FT_CTYPE   := $(addprefix ft_ctype/, $(FT_CTYPE))

FT_LIST    := ft_lstadd_back.c \
              ft_lstadd_front.c \
              ft_lstclear.c \
              ft_lstdelone.c \
              ft_lstiter.c \
              ft_lstlast.c \
              ft_lstmap.c \
              ft_lstnew.c \
              ft_lstsize.c
FT_LIST    := $(addprefix ft_list/, $(FT_LIST))

FT_STDIO   := ft_get_next_line.c \
              ft_printf/form_character.c \
              ft_printf/form_float.c \
              ft_printf/form_integer.c \
              ft_printf/form_number.c \
              ft_printf/form_percent.c \
              ft_printf/form_pointer.c \
              ft_printf/form_string.c \
              ft_printf/form_unsigned.c \
              ft_printf/form_unsigned_extra.c \
              ft_printf/format_parsers.c \
              ft_printf/ft_printf.c \
              ft_putchar.c \
              ft_putnchar.c \
              ft_putchar_fd.c \
              ft_putendl_fd.c \
              ft_putnbr_fd.c \
              ft_putstr.c \
              ft_putnstr.c \
              ft_putstr_fd.c \
              ft_putnstr_fd.c
FT_STDIO   := $(addprefix ft_stdio/, $(FT_STDIO))

FT_STDLIB  := ft_abs.c \
              ft_atoi.c \
              ft_calloc.c \
              ft_qsort.c \
              ft_realloc.c \
              ft_ftoa.c \
              ft_itoa.c \
              ft_utoa.c
FT_STDLIB  := $(addprefix ft_stdlib/, $(FT_STDLIB))

FT_STRING  := ft_memccpy.c \
              ft_memchr.c \
              ft_memcmp.c \
              ft_memcpy.c \
              ft_memmove.c \
              ft_memset.c \
              ft_split.c \
              ft_strchr.c \
              ft_strdup.c \
              ft_strjoin.c \
              ft_strisnumeric.c \
              ft_strisspace.c \
              ft_strlcat.c \
              ft_strlcpy.c \
              ft_strlen.c \
              ft_strmapi.c \
              ft_strmatch.c \
              ft_strcmp.c \
              ft_strncmp.c \
              ft_strstr.c \
              ft_strnstr.c \
              ft_strrchr.c \
              ft_strrev.c \
              ft_strtolower.c \
              ft_strtoupper.c \
              ft_strtrim.c \
              ft_substr.c
FT_STRING  := $(addprefix ft_string/, $(FT_STRING))

FT_STRINGS := ft_bzero.c
FT_STRINGS := $(addprefix ft_strings/, $(FT_STRINGS))

SRCS       := $(FT_CTYPE) $(FT_LIST) $(FT_STDIO) $(FT_STDLIB) $(FT_STRING) $(FT_STRINGS)
OBJS       := $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS       := $(SRCS:%.c=$(DEPDIR)/%.d)

PREBUILD_MSG = "$(GREEN)==>$(WHITE) Creating target $(NAME)...$(NOCOLOR)\n"
ifneq ($(findstring $(MAKECMDGOALS), so $(NAMESO)),)
    PREBUILD_MSG = "$(GREEN)==>$(WHITE) Creating target $(NAMESO)...$(NOCOLOR)\n"
endif
PRECOMPILE_MSG = "  $(BLUE)->$(NOCOLOR) Compiling source files...\n"

all: $(NAME)
$(NAME): $(OBJS)
	@printf $(PREBUILD_MSG)
	@printf "  $(BLUE)->$(NOCOLOR) Creating static library archive...\n"
	@$(AR) $@ $?
	@printf "$(GREEN)==>$(WHITE) Finished making: $(NAME)\n"
.PHONY: all

so: CFLAGS += -fpic
so: $(NAMESO)
$(NAMESO): $(OBJS)
	@printf $(PREBUILD_MSG)
	@printf "  $(BLUE)->$(NOCOLOR) Creating dynamically linked shared library...\n"
	@$(CC) -shared -o $@ $^
	@printf "$(GREEN)==>$(WHITE) Finished making: $(NAMESO)\n"
.PHONY: so

test: $(NAME)
	@$(MAKE) -C test MAKEFLAGS=
	@./test/test
	@-rm -f test/test
.PHONY: test

$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	@printf $(PREBUILD_MSG)
	@printf $(PRECOMPILE_MSG)
	@$(eval PREBUILD_MSG="")
	@$(eval PRECOMPILE_MSG="")
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -MF $(DEPDIR)/$*.tmp -c -o $@ $<
	@$(POST_COMPILE)

$(OBJDIR):
	@mkdir -p $(OBJDIR)/ft_ctype
	@mkdir -p $(OBJDIR)/ft_list
	@mkdir -p $(OBJDIR)/ft_stdio/ft_printf
	@mkdir -p $(OBJDIR)/ft_stdlib
	@mkdir -p $(OBJDIR)/ft_string
	@mkdir -p $(OBJDIR)/ft_strings

$(DEPDIR):
	@mkdir -p $(DEPDIR)/ft_ctype
	@mkdir -p $(DEPDIR)/ft_list
	@mkdir -p $(DEPDIR)/ft_stdio/ft_printf
	@mkdir -p $(DEPDIR)/ft_stdlib
	@mkdir -p $(DEPDIR)/ft_string
	@mkdir -p $(DEPDIR)/ft_strings

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

clean:
	@printf "$(GREEN)==>$(WHITE) Tidying install...$(NOCOLOR)\n"
	@printf "  $(BLUE)->$(NOCOLOR) Removing object files...\n"
	@-rm -rf $(OBJDIR)
	@printf "  $(BLUE)->$(NOCOLOR) Removing make dependency files...\n"
	@-rm -rf $(DEPDIR)
.PHONY: clean

fclean: clean
	@printf "  $(BLUE)->$(NOCOLOR) Removing static library files...\n"
	@-rm -f $(NAME)
	@printf "  $(BLUE)->$(NOCOLOR) Removing shared library files...\n"
	@-rm -f $(NAMESO)
.PHONY: fclean

re:
	@$(MAKE) fclean MAKEFLAGS=
	@$(MAKE) all MAKEFLAGS=
.PHONY: re

help:
	@printf "The following are some of the valid targets for this Makefile:\n"
	@printf "... all (the default if no target is provided)\n"
	@printf "... so\n"
	@printf "... test\n"
	@printf "... clean\n"
	@printf "... fclean\n"
	@printf "... re\n"
.PHONY: help

# Do not include dependency files if the current goal is
# set to clean/fclean/re.
ifeq ($(findstring $(MAKECMDGOALS), clean fclean re),)
    -include $(DEPS)
endif
