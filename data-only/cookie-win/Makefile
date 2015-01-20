TARGET = cookie-win
LIBS = -lm
CC = gcc
CFLAGS = -g -w -ggdb -static -fno-stack-protector -z execstack

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

run: $(TARGET)
	@echo Going to run $(TARGET) ...
	./$(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

