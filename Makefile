
NAME = ft_ls

IDIR = ./incs/
INCS = libft.h	\
	   ft.h
INCC = $(addprefix $(IDIR), $(INCS))

LDIR = ./libft
LIBS = -lft

SDIR = ./srcs/
SRCS = ft_freelst.c		\
	   ft_ls.c			\
	   ft_lstcrea.c		\
	   ft_lstpusbk.c	\
	   ft_lstpusfrt.c	\
	   ft_sortlist.c	\
	   ft_sortrev.c		\
	   main.c			\
	   print.c			\
	   print_lst.c

SRCC = $(addprefix $(SDIR),$(SRCS))

ODIR = ./objs/
OBJS = $(SRCS:.c=.o)
OBCC = $(addprefix $(ODIR),$(OBJS))

FLAG = -g -Wall -Werror -Wextra

$(NAME): $(OBCC)
	make -C ./libft/
	gcc $(FLAG) $(OBCC) -L$(LDIR) $(LIBS) -o $(NAME)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(ODIR)
	gcc $^ $(FLAG) -c -o $@ -I$(IDIR)

all: $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	@make -C ./libft/ clean
	/bin/rm -f $(NAME)

re: fclean all
