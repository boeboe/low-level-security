TARGET = strcpy
LIBS = -lm
CC = gcc
CFLAGS = -g -O0 -w -fno-stack-protector -z execstack -D_FORTIFY_SOURCE=0
#CFLAGS = -g -O0 -w -ggdb -fno-stack-protector -z execstack
LDFLAGS = -static


.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -Wall $(LIBS) -o $@

run: $(TARGET)
	@echo Going to run $(TARGET) ...
	./$(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

