#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        int N;
        int i,j;
        char a[1005][15];
        int sj[1005],k[1005];
        int M;
        int m[1005];
        while(scanf("%d",&N)!=EOF)
        {
                memset(a,0,sizeof(a));
                memset(sj,0,sizeof(sj));
                memset(k,0,sizeof(k));
                memset(m,0,sizeof(m));
                for(i=0;i<N;i++)
                        scanf("%s %d %d",a[i],&sj[i],&k[i]);
                scanf("%d",&M);
                for(i=0;i<M;i++)
                        scanf("%d",&m[i]);
                for(i=0;i<M;i++)
                {
                        for(j=0;j<N;j++)
                        {
                                if(sj[j]==m[i])
                                {
                                        printf("%s %d\n",a[j],k[j]);
                                        break;
                                }
                        }
                }
        }
        return 0;
}
