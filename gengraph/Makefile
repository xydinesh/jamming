CC = gcc
CFLAGS = -O3
#CFLAGS = -O0 -g3 -Werror -Wall
INCLUDES= -I.
EXECUTABLES = gen
LIB = -lpthread
all :  $(EXECUTABLES) 

gen : main.c graph.c graph.h bitop.h gen.c gen.h
	$(CC) $(CFLAGS) -o gen *.c $(INCLUDES) $(LIB)
clean :
	rm -f *.o \#* $(EXECUTABLES) *~

