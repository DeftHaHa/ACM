#include<stdio.h>
#include<string.h>
int main()
{
        char a[10];
        memset(a,0,sizeof(a));
        scanf("%s",a);
        printf("Hello %s",a);
        return 0;
}
