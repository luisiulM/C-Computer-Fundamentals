#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	
	for (i = 0; i < argc; i++) {
		char *arg = argv[i];
		printf("Argument %d = %s\n", i, arg);
	}
	return 0;
}