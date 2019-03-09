#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cmp(const void *a,const void *b)
{
        return *(char *)a>*(char *)b;
}
int main()
{
        int N;
        char a[205];
        char ans[205];
        int i,j;
        int flag,tot;
        scanf("%d%*c",&N);
        while(N--)
        {
                tot=0;
                memset(a,0,sizeof(a));
                memset(ans,0,sizeof(ans));
                scanf("%s",a);
                for(i=0;a[i]!=0;i++)
                {
                        flag=0;
                        for(j=0;j<tot;j++)
                        {
                                if(ans[j]==a[i])
                                {
                                        flag=1;
                                        break;
                                }
                        }
                        if(!flag)
                        {
                                ans[tot++]=a[i];
                        }
                }
                qsort(ans,tot,sizeof(ans[0]),cmp);
                printf("%s\n",ans);
        }
        return 0;
}
