#include<stdio.h>
#include<string.h>
int main()
{
        char a[100];
        memset(a,0,sizeof(a));
        gets(a);
        puts(a);
        return 0;
}
