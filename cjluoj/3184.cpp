#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
        int N;
        int n[105][105];
        int i,j;
        while(scanf("%d",&N)!=EOF)
        {
                if(N==0) break;
                for(i=1;i<=N;i++)
                        for(j=1;j<=N;j++)
                                scanf("%d",&n[i][j]);
                int sumj[105];
                int ans=0xc0c0c0c0;
                int sum,maxsum;
                for(i=1;i<=N;i++)
                {
                        for(j=i;j<=N;j++)
                        {
                                memset(sumj,0,sizeof(sumj));
                                for(int k=1;k<=N;k++)
                                {
                                        for(int z=i;z<=j;z++)
                                        {
                                                sumj[k]+=n[k][z];
                                        }
                                }
                                sum=0;
                                maxsum=0xc0c0c0c0;
                                for(int x=1;x<=N;x++)
                                {
                                        sum+=sumj[x];
                                        if(sum<0) sum=0;
                                        maxsum=max(sum,maxsum);
                                }
                                ans=max(ans,maxsum);
                        }
                }
                printf("%d\n",ans);
        }
        return 0;
}
