#include<stdio.h>
#include<math.h>
int jc(int n)
{
        int i;
        int ans=1;
        for(i=1;i<=n;i++)
                ans*=i;
        return ans;
}
int main()
{
        int n,m;
        int i;
        while(scanf("%d%d",&n,&m)!=EOF)
        {
                printf("%d\n",jc(n)/(jc(abs(m-n))*jc(m)));
        }
        return 0;
}
