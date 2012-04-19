CC = g++
CFLAGS = 
INCLUDES= -I .
LIB = -lm 
EXECUTABLES = ZigZag
SRC = ZigZag.cpp 

all :  ${EXECUTABLES}

ZigZag: ${SRC}
	${CC} ${CFLAGS} -o $@  ${SRC} ${INCLUDES} ${LIB}

clean :
	rm -f *.o \#* PI* ${EXECUTABLES} core *~ ../include/*~

