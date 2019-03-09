#include<cstdio>
#include<cstring>
int main()
{
        int s;
        int M;
        int i;
        int t;
        int a[1005];
        while(scanf("%d",&M)!=EOF)
        {
                s=0;
                t=0;
                memset(a,0,sizeof(a));
                for(i=0;i<M;i++)
                {
                      scanf("%d",&a[i]);
                      s^=a[i];
                }
                for(i=0;i<M;i++)
                {
                        if(a[i]>(s^a[i]))
                                t++;
                }
                printf("%d\n",t);
        }
        return 0;
}
