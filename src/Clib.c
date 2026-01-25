#include "../inc/Clib.h"
#include "../inc/Cdef.h"
#include "../inc/Cchar.h"

char *getenv(const char *name) {
	size_t len = charlen(name);
	for (char **env = __environ;*env;env++) {
		if (!charncmp(*env, name, len) && (*env)[len] == '=') {
			return *env+len+1;
		}
	}
	return 0;
}
