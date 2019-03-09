#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
        int a[10005];
        int b[10005];
        int N;
        int i;
        int tot;
        while(scanf("%d",&N)!=EOF)
        {
                tot=0;
                memset(b,0,sizeof(b));
                memset(a,0,sizeof(a));
                for(i=0;i<N;i++)
                {
                        scanf("%d",&a[i]);
                        b[i]=a[i];
                }
                sort(a,a+N);
                for(i=0;i<N;i++)
                {
                        if(a[i]!=b[i]) tot++;
                }
                if(tot<=2) printf("YES\n");
                else printf("NO\n");
        }
        return 0;
}
