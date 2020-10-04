#include <stdio.h>

void nochange(int p)
{
	printf("Modifying integer at address %d\n", &p);
	p *= 7;
}

void change(int *p)
{
	printf("Modifying integer at address %d\n", p);
	p[0] *= 7;
}

void main()
{
	int x = 7;
	int *p = &x;
	
	printf("&x = %d\n", &x);
	printf("x = %d\n", x);
	nochange(x);
	printf("x = %d\n", x);		
	change(&x);
	printf("x = %d\n", x);
}
