ASMSRCS = func6.asm 
ASMOBJECTS = $(ASMSRCS:.asm=.a)
ASMFLAGS = -f elf

CSRCS = option.c root_integral.c main.c 
COBJECTS = $(CSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -m32

all: $(ASMOBJECTS) $(COBJECTS) MAIN

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

%.a: %.asm
	nasm $(ASMFLAGS) $< -o $@


MAIN:
	gcc $(CFLAGS) -o main $(ASMOBJECTS) $(COBJECTS) -lm


clean:
	rm -f *.o *.a

