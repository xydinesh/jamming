CC = g++
CFLAGS = 
INCLUDES= -I .
LIB = -lm 
EXECUTABLES = ColorfulTilesEasy
SRC = ColorfulTilesEasy.cpp 

all :  ${EXECUTABLES}

ColorfulTilesEasy: ${SRC}
	${CC} ${CFLAGS} -o $@  ${SRC} ${INCLUDES} ${LIB}

clean :
	rm -f *.o \#* PI* ${EXECUTABLES} core *~ ../include/*~

