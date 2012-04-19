CC=gcc
CFLAGS= -c -Wall -Werror
LDFLAGS=-lm
INCLUDES= -I.
SOURCES= main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= pow

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(INCLUDES) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(EXECUTABLE) *~ *.o
