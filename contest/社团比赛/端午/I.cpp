#include<cstdio>
#include<cmath>
#include<cstring>
int main()
{
        int n;
        int i;
        int t;
        bool a[100005];
        while(scanf("%d",&n)!=EOF)
        {
                memset(a,false,sizeof(a));
                for(i=0;i<n-1;i++)
                {
                        scanf("%d",&t);
                        a[t]=true;
                }
                for(i=1;i<=n+1;i++)
                {
                        if(a[i]==false)
                        {
                                printf("%d\n",i);
                                break;
                        }
                }
        }
}
