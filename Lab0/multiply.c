#include <stdio.h>
#include <stdlib.h>

int multiply(int a) {
    int res = 0;
    int b = rand() % 100;
    while (b > 0) {
        if (b % 2 == 1) res += a;
        a <<= 1;
        b >>= 1;
    }
    return res;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s a b\n", argv[0]);
		return -1;
    }
    srand(12345);
    printf("%d\n", multiply(atoi(argv[1])));
}