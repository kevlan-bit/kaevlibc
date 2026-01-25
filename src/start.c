#include "../inc/sys.h"

char **__environ;

__attribute__((noreturn))
void __libc_start(void *stack) {
	unsigned long *sp = (unsigned long*)stack;
	int argc = *sp++;
	char **argv = (char**)sp;
	sp += argc+1;
	char **envp = (char**)sp;
	__environ = envp;
	while (*sp) sp++;
	sp++;
	while (sp[0]) {
		unsigned long type = sp[0];
		unsigned long value = sp[1];
		sp += 2;
	}
	extern int main(int, char**, char**);
	sys_exit(main(argc, argv, envp));
}
