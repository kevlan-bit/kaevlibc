#include "../inc/CIO.h"
#include "../inc/Cchar.h"
#include "../inc/Cmemory.h"
#include "../inc/Cerror.h"

int main(int argc, char** argv) {
	memory_block_t b;
	if (allocmem(1024, &b) != 1) return 1;
	charcpy(b.ptr, "Hello world!");
	printf("%s\n", (char*)b.ptr);
	freemem(&b);
	return 0;
}
