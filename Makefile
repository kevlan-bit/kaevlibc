ASM=as
LD=ld
CC=gcc
CCFLAGS=-ffreestanding -fno-pie -nostdlib
TARGET=test
OBJS=build/crt0.o build/sys.o build/start.o build/test.o build/Cchar.o build/CIO.o build/Clib.o build/Cmemory.o build/Cerror.o

all: build/$(TARGET)

build/$(TARGET): $(OBJS)
	ld -o $@ -e _start $(OBJS)

build/%.o: src/asm/%.s
	$(ASM) -o $@ $<

build/%.o: src/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

build/%.o: tests/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf build/*
