CC      = gcc
CFLAGS  = -Wall -Wextra -Iinclude
LIBS    = -lncurses

SRC     = src/main.c src/intro.c
TARGET  = hail_mary

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
