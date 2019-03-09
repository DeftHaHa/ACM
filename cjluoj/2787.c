#include<stdio.h>
int main()
{
        int n;
        while(scanf("%d",&n)!=EOF)
        {
                if(n==0) printf("2^0 = 1\n");
                else printf("2^%d = %d\n",n,2<<(n-1));
        }
        return 0;
}
