#include<stdio.h>
int f(int A,int B,int n)
{
        if(n==1)
                return 1;
        else if(n==2)
                return 1;
        else
                return (A*f(A,B,n-1)+B*f(A,B,n-2))%7;
}

int main()
{
        int ans;
        int A,B,n;
        int i;
        while(1)
        {
                scanf("%d%d%d",&A,&B,&n);
                if(A==0&&B==0&&n==0) break;
                n%=49;
                ans=f(A,B,n);
                printf("%d\n",ans);
        }
        return 0;
}
