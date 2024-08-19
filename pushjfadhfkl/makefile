CC = cc
CFLAGS = -Werror -Wextra -Wall -g3
RM = rm -rf
NAME = push
OBJS = $(SRCS:.c=.o)

SRCS = 	error.c \
		initialize.c \
		initialize_2.c \
		verif_value.c \
		lstaddback.c \
		lstnew.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		free.c \
		littlesort.c \
		push_swap_utils.c \
		push_swap_for_a_lot.c \
		presort.c \
		main.c 
		

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
	cc -o push_swap $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re