#include <stdio.h>
#include <string.h>

void f(int n) {
	for (int i = 0; i < n * 2 - 1; ++i) {
		int k = i<n?i:2*(n-1)-i; // ²¹È«Õâ¾ä´úÂë
		for (int j = 0; j < n - k - 1; ++j) {
			printf(" ");
		}
		for (int j = 0; j < k * 2 + 1; ++j) {
			if (j&1) {
				printf(" ");
			} else {
				printf("*");
			}
		}
		printf("\n");
	}
}

int main() {
	f(14);
	return 0;
}
