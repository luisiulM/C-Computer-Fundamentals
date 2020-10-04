#include <stdio.h>
#include <stdlib.h>

void main() 
{
	int tall;
	int gjett;
	time_t t = time(NULL);
	
	srand(t*t*t);
	tall = rand() % 100;
	
	// This is debugging stuff... 
	//printf("time = %d\n", t);
	//printf("Tallet er %d\n", tall);

	while (1) {
		printf("Jeg tenker paa et tall mellom 0 og 100.  Hva gjetter du paa?\n");
		scanf("%d", &gjett);
		if (gjett == tall) {
			printf("Riktig!\n");
			return;
		}
		if (gjett < tall) {
			printf("Feil... jeg tenker paa et hoyere tall.\n");
		}
		else {
			printf("Feil... jeg tenker paa et lavere tall.\n");
		}
	}
}
