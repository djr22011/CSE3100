#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n; //the number the user wants to check for happiness

	printf("n = ");
	scanf("%d", &n);

	int m = n; //m remembers the original value so you can report it at the end of the program
	//TODO
	//add code below

	while (n != 1 && n != 4)
	{
		int sum = 0; 
		while(n > 0)
		{
			int digit = n%10;
			sum += digit * digit;
			n/=10;
		}

		n = sum;
		printf("%d\n", n);
	}


	if(n==1) printf("%d is a happy number.\n", m);
	else printf("%d is NOT a happy number.\n", m);
	return 0;
}