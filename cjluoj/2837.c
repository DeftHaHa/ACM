#include<stdio.h>
int main()
{
        int n;
        while(scanf("%d",&n)!=EOF)
        {
                if(n==-1) break;
                while(n>0)
                {
                        printf("%d",n%10);
                        n/=10;
                }
                printf("\n");
        }
        return 0;
}
