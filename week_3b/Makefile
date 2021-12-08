CFLAGS=-Wall -Werror -g -O0

all: main

main: main.o flash_simulator.o spi_flash.h
	cc -o main main.o flash_simulator.o

%.o : %.c
	cc ${CFLAGS} -c $< -o $@

test: main
	@ ./main

clean:
	rm -f *.o
