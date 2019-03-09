#include <stdio.h>

void print(int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j <= n + i - 1; ++j) {
			if ( j==n-i-1) {
				printf("*");
			} else if (j == n + i - 1) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	for (int i = 0; i < n * 2 - 1; ++i) {
		printf("*");
	}
	printf("\n");
}


int main()
{
	for (int i = 1; i <= 16; i *= 2) {
		print(i);
	}
	return 0;
}
