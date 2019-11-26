main: main.c libmyBank.a
	gcc -Wall -o main main.c libmyBank.a

libmyBank.a: myBank.c
	gcc -Wall -c myBank.c -o myBank.o
	ar rcs libmyBank.a myBank.o
	
clean:
	rm -f *.o *.so *.a main
	
all: main