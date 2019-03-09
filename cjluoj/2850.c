#include<stdio.h>
int ans;
int cc(int n)
{
        if(n>=10) return n;
        else if(n&1)
        {
                n+=5;
                ans++;
                cc(n);
        }
        else
        {
                n-=3;
                ans++;
                cc(n);
        }
}
int main()
{
        int x;
        while(scanf("%d",&x)!=EOF)
        {
                ans=0;
                cc(x);
                printf("%d\n",ans+1);

        }
        return 0;
}
