CC = g++
CFLAGS = 
INCLUDES= -I .
LIB = -lm 
EXECUTABLES = Shuffling
SRC = Shuffling.cpp 

all :  ${EXECUTABLES}

Shuffling: ${SRC}
	${CC} ${CFLAGS} -o $@  ${SRC} ${INCLUDES} ${LIB}

clean :
	rm -f *.o \#* PI* ${EXECUTABLES} core *~ ../include/*~

