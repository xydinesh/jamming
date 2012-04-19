CC = g++
CFLAGS = 
INCLUDES= -I .
LIB = -lm 
EXECUTABLES = CondorcetVoting
SRC = CondorcetVoting.cpp 

all :  ${EXECUTABLES}

CondorcetVoting: ${SRC}
	${CC} ${CFLAGS} -o $@  ${SRC} ${INCLUDES} ${LIB}

clean :
	rm -f *.o \#* PI* ${EXECUTABLES} core *~ ../include/*~

