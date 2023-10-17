CC = cc
FLAGS = -Wall -Wextra -Werror

all: rush-02 

rush-02: main.o helloworld.o
	${CC} ${FLAGS} $^ -o $@
	./rush-02
main.o: main.c 
	${CC} ${FLAGS} -c $^ -o $@
helloworld.o: helloworld.c
	${CC} ${FLAGS} -c $^ -o $@
fclean:
	rm -f *.o rush-02
