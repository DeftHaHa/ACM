#include<stdio.h>
#include<string.h>
int a[1000000];
int is_p(int n)
{
        int i;
        for(i=2;i*i<=n;i++)
        {
                if(n%i==0) return 0;
        }
        return 1;
}
int main()
{
        int n,m;
        int l,r;
        int i,j;
        int ans;
        while(scanf("%d",&n)!=EOF)
        {
                memset(a,0,sizeof(a));
                for(i=1;i<=n;i++)
                        scanf("%d",&a[i]);
                scanf("%d",&m);
                while(m--)
                {
                        scanf("%d%d",&l,&r);
                        ans=0;
                        for(i=l;i<=r;i++)
                        {
                                if(is_p(i)==1)
                                {
                                        for(j=1;j<=n;j++)
                                        {
                                                if(a[j]%i==0) ans++;
                                        }
                                }
                        }
                        printf("%d\n",ans);
                }
        }
        return 0;
}
