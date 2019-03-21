SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(OBJECTS)

%.o: %.c
	gcc -c -g $<

clean:
	rm $(OBJECTS)
