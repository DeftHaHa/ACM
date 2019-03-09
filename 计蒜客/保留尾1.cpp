#include <stdio.h>

void f(int x)
{
	int i;
	for (i = 0; i < 32; i++) {
		printf("%d", (x>>(31-i))&1);
	}
	printf("   ");
	x =   x&-x   ;//??????
	for (i = 0; i < 32; i++) {
		printf("%d", (x>>(31-i))&1);
	}
	printf("\n");
}

int main()
{
	f(1234);
	f(2332);
	return 0;
}
