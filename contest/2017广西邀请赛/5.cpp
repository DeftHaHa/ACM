#include<cstdio>
using namespace std;
int main()
{
        int n,p;
        int a[100005];
        int i;
        int pi;
        while(scanf("%d%d",&n,&p)!=EOF)
        {
                for(i=1;i<=n;i++)
                {
                        scanf("%d",&a[i]);
                }
                while(p--)
                {
                        scanf("%d",&pi);
                        if(pi!=1) ans=a[1]
                        for(i=2;i<=n;i++)
                        {
                                if(i!=pi) ans=ans&a[i];
                        }
                }
        }
        return 0;
}
