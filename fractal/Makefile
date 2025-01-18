CC = gcc
SOURCES = image.c fractal.c test_code.c
OBJECTS = $(SOURCES:.c=.o)
EXEC = fractal_program

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

clean:
	rm -f $(OBJECTS) $(EXEC)
