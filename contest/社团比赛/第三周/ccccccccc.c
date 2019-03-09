#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
 const int *p = a;
 const int *q = b;

 return *p - *q;
}
int main()
{
        int T;
        int N,L;
        int t[20000],t_1[20000];
        int tj[20000],tji,tjg;
        int i,j;
        int temp;
        int h,m,s;
        int tj_1[20000],tj_1i;
        scanf("%d",&T);
        while(T--)
        {
                scanf("%d%d",&N,&L);
                for(i=0;i<N;i++)
                {
                        scanf("%d:%d:%d",&h,&m,&s);
                        t[i]=h*3600+m*60+s;
                        t_1[i]=t[i];
                }
                qsort(t_1,N,sizeof(t_1[1]),cmp);         //或者 qsort(&t_1[0],N,sizeof(t_1[0]),cmp);
                tj[0]=t_1[0];
                tji=0;
                tjg=1;
                for(i=1;i<N;i++)
                {
                        if(t_1[i]>=tj[tji]+L)
                        {
                                tji++;
                                tj[tji]=t_1[i];
                                tjg++;
                        }
                }
                printf("%d\n",tjg);
                tj_1i=0;
                for(i=0;i<=tji;i++)
                {
                        for(j=0;j<N;j++)
                        {
                                if(tj[i]==t[j])
                                        {
                                                tj_1[tj_1i]=j+1;
                                                tj_1i++;
                                        }
                        }
                }
                qsort(tj_1,tjg,sizeof(tj_1[0]),cmp);
                for(i=0;i<tjg-1;i++)
                        printf("%d ",tj_1[i]);
                printf("%d",tj_1[tjg-1]);
                printf("\n");
        }
        return 0;
}
