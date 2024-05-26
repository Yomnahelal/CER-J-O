
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =
SOURCES = main.c athlete.c file_operations.c statistics.c utils.c
OBJECTS = $(SOURCES:.c=.o)
EXEC = cer-j-o

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)

.PHONY: all clean
