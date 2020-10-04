#include <stdio.h>
#include <stdlib.h>

void main(void)
{

// type   navn på variabel
//   |			|
	int 	my_first_variable;
	int		my_second_variable;
	int		sum;


	my_first_variable = 7;
	my_second_variable = 6;

	if(my_first_variable > my_second_variable)
	{
		printf("min første variabel var mindre enn min andre variabel\n");
	}

	sum = my_first_variable + my_second_variable;

	printf("Hello, world\n");
	printf("Det var skikkelig dårlig vær i dag\n");

	printf("Summen av variablene mine er: %d\n", sum);
}






