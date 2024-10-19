#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;

	printf("n = ");
	scanf("%d", &n);

	double pi = 0.;
	double power16 = 1.0; //16 ** 0 = 1

	//TODO
	//add code below 

	for(int i = 0; i <= n; i ++)
	{
		
		//The current term for i iterations
		double term = (4.0 / (8.0 * i + 1.0))
					- (2.0 / (8.0 * i + 4.0))
					- (1.0 / (8.0 * i + 5.0))
					- (1.0 / (8.0 * i + 6.0));

		pi += term / power16; //pi becomes the term * 1/16**i
		power16 *= 16; //16**i increases by 1 each time
	}
	
	printf("PI = %.10f\n", pi);
	return 0;
}