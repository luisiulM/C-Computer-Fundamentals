#include <stdio.h>

char lesbokstav()
{
	char c;
	
	// Les neste bokstav fra brukeren, men ignorer linjeskift
	while (1) {
		scanf("%c", &c);
		//if (!(c == '\r' || c == '\n'))
		//	return c;
		if (c != '\r' && c != '\n')
			return c;
	}
}

void main()
{
	int lo = 0;
	int hi = 99;	
	char b;
	
	printf("Minste mulige tall?\n");
	scanf("%d", &lo);
	printf("Hoyeste mulige tall?\n");
	scanf("%d", &hi);
	
	while (lo <= hi) {
		int gjett = (lo + hi) / 2;
		printf("Jeg gjetter paa %d\n", gjett);
		printf("Er det riktig, for lavt, eller for hoyt (r/l/h)?\n");
		b = lesbokstav();
		if (b == 'r') {
			printf("Jippi.\n");
			return;
		}
		else if (b == 'l') {
			lo = gjett+1;
		}
		else if (b == 'h') {
			hi = gjett-1;
		}			
	}	
}


void gammelmain()
{
	int gjett;
	char b;
	
	gjett = 0;
	while (gjett < 100) {
		printf("Jeg gjetter paa %d\n", gjett);
		printf("Er det riktig (j/n)?\n");
		b = lesbokstav();
		if (b == 'j') {
			printf("Jippi.\n");
			return;
		}
		gjett = gjett + 1;
	}

	/* Ekvivalent med koden over, ved bruk av
	   for loop i stedet for while loop:
	
	for (gjett = 0; gjett < 100; gjett++) {
		printf("Jeg gjetter paa %d\n", gjett);
		printf("Er det riktig (j/n)?\n");
		b = lesbokstav();
		if (b == 'j') {
			printf("Jippi.\n");
			return;
		}
	}
	*/
}
