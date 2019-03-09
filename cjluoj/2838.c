#include<stdio.h>
int main()
{
        double n;
        double i,k;
        double ans;
        int t;
        while(scanf("%lf",&n)!=EOF)
        {
                k=1;
                t=0;
                ans=0;
                for(i=1;1/i>n;i+=2)
                {
                        ans+=k/i;
                        k*=-1;
                        t++;
                }
                ans+=k/i;
                printf("%.6lf %d\n",ans*4,t+1);
        }
        return 0;
}
