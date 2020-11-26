OBJECTS  = main.o internal.o io.o info.o game.o utils.o
CFLAGS   = -Wall
COMPILER = gcc
SOFTWARE = lox 

$(SOFTWARE): $(OBJECTS)
	$(COMPILER) $(CFLAGS) -o $(SOFTWARE) $(OBJECTS)

$(OBJECTS): utils.h
	$(COMPILER) $(CFLAGS) -c $*.c

clean:
	rm -rf $(SOFTWARE) $(OBJECTS)

