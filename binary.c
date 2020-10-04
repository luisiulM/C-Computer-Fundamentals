#include <stdio.h>

void printbinary(unsigned int i)
{
	char bit[32];
	int x, j;
	
	printf("i = %u\n", i);
	x = 0;
	while (i > 0) {
		if (i % 2 != 0) {
			bit[x++] = '1';
		}
		else {
			bit[x++] = '0';
		}
		i /= 2;
	}
	for (j = x-1; j >= 0; j--) {
		printf("%c", bit[j]);
	}	
	printf("\n");
}

int main()
{
	int i;
	
	while (1) {
		printf("\nSkriv inn et tall:\n");
		scanf("%d", &i);
		printf("i = %d\n", i);
		if (i >= 0) { 
			printbinary(i);
		}
		else {
			// It works for negative numbers, too!
			// -1 will be converted silently to
			// 4294967295, i.e. the same bit-string
			printbinary(i);
		}
	}
	return 0;
}
