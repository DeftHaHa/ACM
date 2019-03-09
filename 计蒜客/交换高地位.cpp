#include <stdio.h>
void print(unsigned int x) {
    for (int i = 31; i >= 0; --i) {
        if (x&(1UL<<i)) printf("1");
        else printf("0");
        if (i % 8 == 0) {
            if (i) printf(" ");
            else printf("\n");
        }
    }
}
int main() {
    unsigned int x;
    scanf("%ud", &x);
    print(x);
    // 在下方填入一行代码 
    x=(x>>24)+(((x<<8)>>24)<<8)+(((x>>8)<<24)>>8)+(x<<24);
    print(x);
    return 0;
}
//123523532
