NAME = philo
CC = clang 
INC = philo.h
FLAGS = -Wall -Wextra -Werror -pthread
SRCS =	philo.c				\
		parsing.c			\
		init_mutex.c		\
		create_threads.c	\
		utils.c				\
		threads.c			\
		lockers.c
	
OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS)

$(OBJS):	$(SRCS) $(INC)
		$(CC) $(FLAGS) -c $(SRCS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all bonus clean fclean re