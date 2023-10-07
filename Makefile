CC = g++
CFLAGS = -Wall -Wextra -std=c++20
LDFLAGS = -Ldependencies -lSDL2
INCLUDES = -Idependencies/SDL2

SRC_DIR = src

SRCS := $(wildcard $(SRC_DIR)/*.cpp)

TARGET = pong

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(TARGET)
