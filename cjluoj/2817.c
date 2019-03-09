#include<stdio.h>
#include<string.h>
int main()
{
        char a[10];
        memset(a,0,sizeof(a));
        int i;
        for(i=0;i<7;i++)
                scanf("%c",&a[i]);
        for(i=0;i<7;i++)
        {
                printf("%c %d %xh\n",a[i],a[i],a[i]);
        }
        return 0;
}
