#include<cstdio>
#include<cstring>
#include<cstdio>
using namespace std;
const int fac[] = {1,1,2,6,24,120,720,5040,40320};
bool vis[10];
void KT(int ans[], int n, int k)
{
        int i,j,t;
        memset(vis, 0, sizeof(vis));
        --k;
        for(i=0;i<n;++i)
        {
                t=k/fac[n-i-1];
                for (j=1;j<=n;j++)
                        if(!vis[j])
                        {
                                if (t == 0) break;
                                --t;
                        }
                ans[i]=j;
                vis[j]=true;
                k%=fac[n-i-1];
        }
}
int main()
{
        int a[10];
        int T,N,k;
        while(scanf("%d",&T)!=EOF)
        {
                if(T==0) break;
                int c=0;
                while(T--)
                {
                        scanf("%d%d",&N,&k);
                        KT(a,N,k);
                        printf("Case %d: ",++c);
                        for(int i = 0; i<N;++i) printf("%d",a[i]);
                        printf("\n");
                }
                printf("\n");
        }
        return 0;
}
