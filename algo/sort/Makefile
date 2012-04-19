CC=g++
CFLAGS= -c -Wall -Werror
LDFLAGS=
INCLUDES= -I.
SOURCES= main.cpp sortalgo.cpp insertsort.cpp mergesort.cpp quicksort.cpp countsort.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE= sortal

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(INCLUDES) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(EXECUTABLE) *~ *.o
