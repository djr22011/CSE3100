#include <stdio.h>

/* This function calculates n-th Catalan number.
 * n is assumed to be non-negative.
 * Do not worry about overflow.
 * Do not print anything in this function.
 * Do not use floating-point numbers (or operations).
 */
long catalan_number(int n)
{
    if (n < 0)
        return 0;

    // TODO
    long catalan = 1; //base case: C0 = 1

    for (int k = 1; k <= n; ++k) //iterates the formuala from 1 - n
    {
        catalan = catalan * (4*k-2) / (k+1); //multiplies the current n by the previous n
    }

    return catalan;
}

/* do not change main function */
int main(void)
{
    int n;

    while (scanf("%d", &n) == 1) {
        if (n < 0) 
            printf("C(%2d) is not defined.\n", n);
        else 
            printf("C(%2d)=%18ld\n", n, catalan_number(n));
    }
    return 0;
}