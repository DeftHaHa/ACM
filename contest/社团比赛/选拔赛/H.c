#include<stdio.h>
#include<string.h>
int main()
{
        int T;
        int N;
        int a[1000];
        int ans[1000];
        int max[1000];
        int maxl,l;
        int i,j,j_1;
        int temp;
        scanf("%d",&T);
        while(T--)
        {
                memset(a,0,sizeof(a));
                scanf("%d",&N);
                for(i=0;i<N;i++)
                {
                        scanf("%d",&a[i]);
                }
                maxl=0;
                for(i=1;i<=1;i++)
                {
                        memset(ans,0,sizeof(ans));
                        ans[0]=a[i];j_1=0;l=1;maxl=0;
                        for(j=i+1;j<N;j++)
                        {
                                if(j+maxl>N) break;
                                if(a[j]>ans[j_1])
                                {
                                        ans[j_1+1]=a[j];
                                        l++;
                                        j_1++;
                                }
                        }
                        if(l>maxl)
                        {
                                maxl=l;
                                memset(max,0,sizeof(max));
                                for(i=0;i<l;i++)
                                        max[i]=ans[i];
                        }
                }
                printf("%d",maxl);
                for(i=0;i<maxl;i++) printf(" %d",max[i]);
                printf("\n");
        }
        return 0;
}
