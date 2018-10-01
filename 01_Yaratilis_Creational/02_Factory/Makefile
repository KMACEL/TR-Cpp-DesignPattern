CC = g++
CFLAGS = -O2 -Wall -Wextra -Werror -std=c++11
LIB = src/Arac.cpp 
MAIN = src/main.cpp
OUT = test

all: run

build: $(MAIN)
	$(CC) $(CFLAGS) $(LIB) $(MAIN) -o $(OUT) 

run: build
	./$(OUT)

clean:
	rm -f $(OUT)

install: $(OUT)
	cp $(OUT) /usr/bin

.PHONY: clean
