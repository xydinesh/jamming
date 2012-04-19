CC=g++
CFLAGS= -c -Wall -Werror
LDFLAGS=
INCLUDES= -I.
SOURCES= main.cpp longseq.cpp sortalgo.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE= sortal

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(INCLUDES) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(EXECUTABLE) *~ *.o
