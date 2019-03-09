#include <stdio.h>
#include <string.h>
char res[5000000];
int main() {
    int n;
    scanf("%d", &n);
    int len = 0;
    for (int i = 1; i <= n; ++i) {
        strcat( res+len+1 , res);
        res[len] = 'A' + i - 1;
        len = strlen(res);
    }
    printf("%s\n", res);
    return 0;
}
