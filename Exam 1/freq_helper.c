#include <assert.h>

//TODO
unsigned firstDigit(unsigned k)
{
	//fill in code below
	//this is the only function on my whole exam that works as intended
	while(k > 10)
		k = k /10; //divide k by 10 until there is 1 digit left
	return k;
}

//TODO
void FirstDigitCount(unsigned *a, unsigned n, unsigned freq[10])
{
	//fill in your code below
	for(int i = 0; i < 10; i++)
	{
		freq[i] = 0; //initilaze all values of freq[] to 0
	}
	for(int i = 0; i < n; i++) //iterate over array a[]
	{
		int digit = firstDigit(a[i]); //find the first digit of value at index i
		freq[digit] += 1; //increase the frequency of the digit we just found by 1
	}
}