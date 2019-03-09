#include<stdio.h>
#include<string.h>
int main()
{
        int n;
        int M;
        int a[151];
        int t;
        int i,j;
        while(1)
        {
                scanf("%d",&n);
                if(n==0) break;
                for(M=2;;M++)
                {
                        memset(a,0,sizeof(a));
                        t=1;
                        j=1;
                        a[1]=1;
                        for(i=1;i<=n;i++)
                        {
                                if((2+M)%i==0)
                                {
                                        printf("%d\n",M);
                                        break;
                                }
                        }
                        if((2+M)%i==0) break;
                }
        }
        return 0;
}
