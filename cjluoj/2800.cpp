#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct product
{
        float w;
        float pt;
        float p;
}p[10005];
int cmp(const product a,const product b)
{
        return a.p>b.p;
}
int main()
{
        int N,M;
        int i;
        float ans;
        while(cin>>N>>M)
        {
                memset(p,0,sizeof(p));
                for(i=0;i<N;i++)
                        cin>>p[i].w;
                for(i=0;i<N;i++)
                {
                        cin>>p[i].pt;
                        p[i].p=p[i].pt/p[i].w;
                }
                sort(p,p+N,cmp);
                ans=0;
                for(i=0;i<N;i++)
                {
                        if(M>=p[i].w)
                        {
                                ans+=p[i].pt;
                                M-=p[i].w;
                        }
                        else
                        {
                                ans+=M*p[i].p;
                                M=0;
                        }
                        if(M==0) break;
                }
                printf("%.2f\n",ans);
        }
        return 0;
}
