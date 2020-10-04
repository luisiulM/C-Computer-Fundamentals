#include <stdio.h>

int checkPrime(int value)
{
	int test = value -1;
	
	while (test > 1){
		if (value % test == 0){
			return 1;
		}
		
		test--;
	}
	
	return 0;
}


int main(void)
{
    int number;
	int result;
	 
	 printf("skriv inn et tall: ");
     scanf("%d",&number);
	 
	 result = checkPrime(number);
	 
	 if (result == 0){
		 printf("%d er et primtall\n",number);
	 }
	 else{
		 printf("%d er Ikke et primtall\n", number);
	 }
}