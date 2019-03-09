#include<cstdio>
#include<cstring>
using namespace std;
int num[100005];
int main ()
{
        int a,b;
        int N,M;
        while(~scanf("%d",&N))
        {
                if(N==0) break;
                scanf("%d",&M);
                memset(num,0,sizeof(num));
                for(int i=1; i<=M; i++)
                {
                        scanf("%d%d",&a,&b);
                        num[a]++;
                        num[++b]--;
                }
                printf("%d",num[1]);
                for(int i=2;i<=N;i++)
                {
                        num[i]+=num[i-1];
                        printf(" %d",num[i]);
                }
                printf ("\n");
        }
        return 0;
}
