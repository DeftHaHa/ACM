#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef pair<int,int> PAIR;
bool cmp(const PAIR &a,const PAIR &b)
{
        if(a.first!=b.first) return a.first<b.first;
        else return a.second<b.second;
}
int main()
{
        pair<int,int> p[1005];
        int N;
        int r,c;
        int x[1005],y[1005];
        int ca=0;
        while(cin>>N)
        {
                if(N==0) break;
                for(int i=0;i<N;i++)
                {
                        cin>>r>>c;
                        p[i].first=r;
                        p[i].second=c;
                        x[i]=r;
                        y[i]=c;
                }
                sort(p,p+N,cmp);
                printf("Case %d:\n",++ca);
                for(int i=0;i<N;i++)
                {
                        int ans1=-1,ans2=-1;
                        for(int j=0;j<N;j++)
                        {
                                if(p[j].first>x[i]&&p[j].second>y[i])
                                {
                                        ans1=p[j].first;
                                        ans2=p[j].second;
                                        break;
                                }
                        }
                        printf("%d %d\n",ans1,ans2);
                }
                printf("\n");
        }
        return 0;
}
