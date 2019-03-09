#include<stdio.h>
#include<math.h>
int main()
{
        int T,N;
        int i,j;
        int n[2000];
        int temp;
        int sum[1000];
        int a,b;
        int ans;
        scanf("%d",&T);
        while(T--)
        {
                ans=0;
                scanf("%d",&N);
                for(i=0;i<2*N;i++)
                        {
                                scanf("%d",&n[i]);
                        }
                for(i=0;i<2*N;i++)
                {
                        for(j=0;j<2*N-i-1;j++)
                        {
                                if(n[j]>n[j+1])
                                {
                                        temp=n[j];
                                        n[j]=n[j+1];
                                        n[j+1]=temp;
                                }
                        }
                }
                for(i=0;i<N;i++)
                {
                        ans+=abs(n[2*N-i-1]-n[i]);
                }
                printf("%d\n",ans);
        }
        return 0;
}
