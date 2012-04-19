CC = g++
CFLAGS = 
INCLUDES= -I .
LIB = -lm 
EXECUTABLES = RectangularIsland
SRC = RectangularIsland.cpp 

all :  ${EXECUTABLES}

RectangularIsland: ${SRC}
	${CC} ${CFLAGS} -o $@  ${SRC} ${INCLUDES} ${LIB}

clean :
	rm -f *.o \#* PI* ${EXECUTABLES} core *~ ../include/*~

