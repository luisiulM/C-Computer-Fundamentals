#include <stdio.h>
#include <stdlib.h>

void min_teller(void)
{
	int j;

	for(j = 10; j > 0; j = j - 1)
	{
		printf("%d\n", j);
	}
}

void min_teller_med_input(int startverdi, int sluttverdi)
{
	int j;
	for(j = startverdi; j <= sluttverdi; j = j + 2)
	{
		printf("%d\n", j);
	}
}


void min_oddetallsteller(int startverdi, int sluttverdi)
{
	int j;
	for(j = startverdi; j <= sluttverdi; j = j + 1)
	{
		if(j % 2 != 0)
		{
			printf("%d\n", j);	
		}
	}
}


int sum(int a, int b)
{
	int retval;

	retval = a + b;

	return retval;
}

int produkt(int a, int b)
{
	int retval;
	retval = a * b;

	return retval;
}

void tell_ned_fra_input(void)
{
	int input;

	printf("Enter a number: ");
	scanf("%d",&input);
	printf("Tallet du skrev inn var: %d\n", input);

	while(input > 0)
	{
		printf("%d\n", input);
		input = input - 1;
	}
}



void main(void)
{
	
	int sum_av_a_og_b;
	int produkt_av_a_og_b;

	sum_av_a_og_b = sum(5, 8);

	printf("Summen av a + b = %d\n", sum_av_a_og_b);

	produkt_av_a_og_b = produkt(5, 6);
	printf("Produktet av a + b = %d\n", produkt_av_a_og_b);

	min_teller_med_input(5, 20);
	
	tell_ned_fra_input();

}
















