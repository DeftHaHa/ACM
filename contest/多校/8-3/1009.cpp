#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        int T;
        int n;
        long long a[100005];
        scanf("%d",&T);
        long long j;
        int i;
        int tot,maxt;
        long long mod;
        long long ansa,ansb;
        int m[100005];
        while(T--)
        {
                scanf("%d",&n);
                if(n&1) maxt=n/2+1;
                else maxt=n/2;
                for(i=0;i<n;i++)
                        scanf("%lld",&a[i]);
                bool flag=false;
                for(j=3;;j++)
                {
                        tot=0;
                        memset(m,0,sizeof(m));
                        for(i=0;i<n;i++)
                        {

                                m[a[i]%j]++;
                                if(m[a[i]%j]>=maxt)
                                {
                                        ansa=j;
                                        ansb=a[i]%j;
                                        flag=true;
                                }
                        }
                        if(flag) break;
                }
                printf("%lld %lld",ansa,ansb);
        }
        return 0;
}
