CC := clang
CFLAGS := -Wall -Wextra -O2
LDFLAGS := -framework IOKit -framework CoreFoundation
TARGET := oolong
SRC := noidlesleep.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
