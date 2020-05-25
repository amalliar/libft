# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 23:55:29 by amalliar          #+#    #+#              #
#    Updated: 2020/05/25 10:08:57 by amalliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL      := /bin/sh
CC         := clang
CFLAGS     := -Wall -Wextra -Werror -fdiagnostics-color -g -pipe \
              -march=native -O2
INCLUDE    := -I./include
AR         := ar -rcs
NAME       := libft.a
NAMESO     := libft.so
OBJDIR     := .obj
DEPDIR     := .dep

FT_CTYPE   := ft_ctype/ft_isalnum.c \
              ft_ctype/ft_isalpha.c \
              ft_ctype/ft_isascii.c \
              ft_ctype/ft_isdigit.c \
              ft_ctype/ft_isprint.c \
              ft_ctype/ft_tolower.c \
              ft_ctype/ft_toupper.c

FT_LIST    := ft_list/ft_lstadd_back.c \
              ft_list/ft_lstadd_front.c \
              ft_list/ft_lstclear.c \
              ft_list/ft_lstdelone.c \
              ft_list/ft_lstiter.c \
              ft_list/ft_lstlast.c \
              ft_list/ft_lstmap.c \
              ft_list/ft_lstnew.c \
              ft_list/ft_lstsize.c

FT_STDIO   := ft_stdio/ft_get_next_line.c \
              ft_stdio/ft_putchar_fd.c \
              ft_stdio/ft_putendl_fd.c \
              ft_stdio/ft_putnbr_fd.c \
              ft_stdio/ft_putstr_fd.c

FT_STDLIB  := ft_stdlib/ft_atoi.c \
              ft_stdlib/ft_calloc.c \
              ft_stdlib/ft_itoa.c \

FT_STRING  := ft_string/ft_memccpy.c \
              ft_string/ft_memchr.c \
              ft_string/ft_memcmp.c \
              ft_string/ft_memcpy.c \
              ft_string/ft_memmove.c \
              ft_string/ft_memset.c \
              ft_string/ft_split.c \
              ft_string/ft_strchr.c \
              ft_string/ft_strdup.c \
              ft_string/ft_strjoin.c \
              ft_string/ft_strlcat.c \
              ft_string/ft_strlcpy.c \
              ft_string/ft_strlen.c \
              ft_string/ft_strmapi.c \
              ft_string/ft_strncmp.c \
              ft_string/ft_strnstr.c \
              ft_string/ft_strrchr.c \
              ft_string/ft_strtrim.c \
              ft_string/ft_substr.c

FT_STRINGS := ft_strings/ft_bzero.c

SRCS       := $(FT_CTYPE) $(FT_LIST) $(FT_STDIO) $(FT_STDLIB) $(FT_STRING) \
              $(FT_STRINGS)
OBJS       := $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS       := $(SRCS:%.c=$(DEPDIR)/%.d)

# Run multiple threads.
MAKEFLAGS  := -j 4 --output-sync=recurse --no-print-directory

# Protect against make incorrectly setting 'last modified' attribute 
# when running in parallel (-j flag).
POST_COMPILE = mv -f $(DEPDIR)/$*.tmp $(DEPDIR)/$*.d && touch $@

# Define some colors for echo:
LGREEN     := \033[1;32m
WHITE      := \033[1;37m
NOC        := \033[0m

all: $(NAME)
$(NAME): $(OBJS)
	@echo -e "$(LGREEN)Linking C static library $(NAME)$(NOC)"
	@$(AR) $@ $?
	@echo "Built target $(NAME)"
.PHONY: all

so: CFLAGS += -fpic
so: $(NAMESO)
$(NAMESO): $(OBJS)
	@echo -e "$(LGREEN)Linking C dynamic library $(NAMESO)$(NOC)"
	@$(CC) -shared -o $@ $^
	@echo "Built target $(NAMESO)"
.PHONY: so

$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -MF $(DEPDIR)/$*.tmp -c -o $@ $<
	@$(POST_COMPILE)
$(OBJDIR):
	@mkdir -p $(OBJDIR)/ft_ctype
	@mkdir -p $(OBJDIR)/ft_list
	@mkdir -p $(OBJDIR)/ft_stdio
	@mkdir -p $(OBJDIR)/ft_stdlib
	@mkdir -p $(OBJDIR)/ft_string
	@mkdir -p $(OBJDIR)/ft_strings
$(DEPDIR):
	@mkdir -p $(DEPDIR)/ft_ctype
	@mkdir -p $(DEPDIR)/ft_list
	@mkdir -p $(DEPDIR)/ft_stdio
	@mkdir -p $(DEPDIR)/ft_stdlib
	@mkdir -p $(DEPDIR)/ft_string
	@mkdir -p $(DEPDIR)/ft_strings
$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

clean:
	@echo -e "$(WHITE)Removing C object files...$(NOC)"
	@-rm -rf $(OBJDIR)
	@echo -e "$(WHITE)Removing make dependency files...$(NOC)"
	@-rm -rf $(DEPDIR)
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
	@echo "... so"
	@echo "... clean"
	@echo "... fclean"
	@echo "... re"
.PHONY: help

# Do not include dependency files if the current goal is
# set to clean/fclean/re.
ifeq ($(findstring $(MAKECMDGOALS), clean fclean re),)
    -include $(DEPS)
endif
