#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> PAIR;
bool cmp(const PAIR &a,const PAIR &b)
{
        if(a.first==b.first)
                return a.second<b.second;
        else if(a.second==b.second)
                return a.first<b.first;
        else return a.first<b.first && a.second<b.second;
}
int main()
{
        int N;
        bool n[705][705];
        int x,y;
        int X,Y;
        pair<int,int> node[505];
        int i;
        int l;
        int ans;
        memset(n,false,sizeof(n));
        memset(node,0,sizeof(node));
        while(scanf("%d",&N)!=EOF)
        {
                for(i=0;i<N;i++)
                {
                        scanf("%d%d",&x,&y);
                        x+=100;
                        y+=100;
                        n[x][y]=true;
                        node[i].first=x;
                        node[i].second=y;
                }
                sort(node,node+N,cmp);
                ans=0;
                for(i=0;i<N;i++)
                {
                        x=node[i].first;
                        y=node[i].second;
                        for(X=x+1;X<705;X++)
                        {
                                if(n[X][y])
                                {
                                        if(!(X-y)&1)
                                        l=X-x;
                                        if(n[x][y+l]&&n[x+l][y+l]) ans++;
                                }
                        }
                }
                printf("%d\n",ans);
                memset(n,false,sizeof(n));
                memset(node,0,sizeof(node));
        }
        return 0;
}
