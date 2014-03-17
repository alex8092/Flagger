CC = gcc

REGEXDIR = Regex
FTDIR = $(HOME)/.ft

CFLAGS = -Wall -Werror -Wextra -I$(INCLUDEDIR) -fPIC
CFLAGS += -I$(FTDIR)/include

DEBUG = true
ifeq ($(DEBUG), true)
	CFLAGS += -ggdb3
else
	CFLAGS += -O3
endif

LDFLAGS_TEST = -L$(FTDIR)/lib -lftcommon -Wl,-rpath,$(FTDIR)/lib
LDFLAGS_TEST += -lftgetnextline -lftastr

LDFLAGS = -shared $(LDFLAGS_TEST)

LD_LIBRARY_PATH=$(FTDIR)/lib:$(LD_LIBRARY_PATH)

NAME = $(LIBDIR)/$(SHORTNAME)
SHORTNAME = libftflagger.so

SRCS =	ft_flagger.c \
		ft_flagger_parse.c \
		ft_flagger_mult.c \
		ft_flagger_single.c \
		ft_flagger_usage.c \
		ft_flagger_opt.c \
		ft_flagger_args.c \
		ft_flagger_info.c \
		ft_flagger_free.c \
		ft_flagger_help.c

SRCS_TEST = main.c

LIBDIR = lib
OBJDIR = obj
TESTDIR = tests
SRCDIR = src
INCLUDEDIR = include/ft

RED = \033[0;31m
GREEN = \033[0;32m
NO = \033[0m

OBJS_BASE = $(SRCS:.c=.o)

OBJS_TEST = $(SRCS_TEST:.c=.o)

OBJS = $(addprefix $(OBJDIR)/, $(OBJS_BASE))
OBJSTEST = $(addprefix $(OBJDIR)/, $(OBJS_TEST))

all: start

print_begin:
	@rm -f .make_errors
	@echo "Compiling ..."

print_error:
	@if [ -e .make_errors ]; then cat .make_errors; fi
	@rm -f .make_errors

test: print_begin $(OBJS) $(OBJSTEST) print_error $(NAME)_test

start: print_begin $(OBJS) print_error $(NAME)

$(NAME)_test: $(OBJSTEST) $(OBJS)
	@$(CC) -o $(TESTDIR)/test.bin $(OBJS) $(OBJSTEST) $(LDFLAGS_TEST)

$(NAME): $(OBJS)
	@mkdir -p $(LIBDIR)
	@$(CC) -o $@ $(OBJS) $(LDFLAGS)

install:
	@chmod +x install.sh
	@./install.sh $(NAME) $(INCLUDEDIR) $(LIBDIR)

uninstall:
	@chmod +x install.sh
	@./install.sh $(NAME) $(INCLUDEDIR) $(LIBDIR) uninstall

$(INCLUDEDIR)/flagger_private.h: $(INCLUDEDIR)/flagger.h
$(OBJDIR)/main.o: $(INCLUDEDIR)/flagger.h
$(OBJDIR)/ft_flagger.o: $(INCLUDEDIR)/flagger_private.h
$(OBJDIR)/ft_flagger_args.o: $(INCLUDEDIR)/flagger_private.h
$(OBJDIR)/ft_flagger_free.o: $(INCLUDEDIR)/flagger_private.h
$(OBJDIR)/ft_flagger_help.o: $(INCLUDEDIR)/flagger_private.h
$(OBJDIR)/ft_flagger_info.o: $(INCLUDEDIR)/flagger_private.h
$(OBJDIR)/ft_flagger_mult.o: $(INCLUDEDIR)/flagger_private.h
$(OBJDIR)/ft_flagger_opt.o: $(INCLUDEDIR)/flagger_private.h
$(OBJDIR)/ft_flagger_parse.o: $(INCLUDEDIR)/flagger_private.h
$(OBJDIR)/ft_flagger_single.o: $(INCLUDEDIR)/flagger_private.h
$(OBJDIR)/ft_flagger_usage.o: $(INCLUDEDIR)/flagger_private.h

$(OBJDIR)/%.o: $(TESTDIR)/%.c
	@mkdir -p $(OBJDIR)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors\
	  && echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors\
	  && echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

clean:
	@echo "Clean objects ..."
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Clean library ..."
	@rm -rf $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re
