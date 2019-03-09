#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct pep
{
        int tot;
        int g;
        int id;
}p[10005];
bool cmp(const pep &a,const pep &b)
{
        if(a.g!=b.g) return a.g>b.g;
        else if(a.tot!=b.tot) return a.tot>b.tot;
        else return a.id<b.id;
}
int main()
{
        int N;
        int K;
        int id,m;
        int mm;
        int i;
        memset(p,0,sizeof(p));
        for(i=0;i<10005;i++) p[i].id=i;
        while(cin>>N)
        {
                for(i=1;i<=N;i++)
                {
                        cin>>K;
                        while(K--)
                        {
                                cin>>id>>m;
                                p[i].g-=m;
                                p[id].g+=m;
                                p[id].tot++;
                        }
                }
                sort(p+1,p+N+1,cmp);
                for(i=1;i<=N;i++)
                {
                        printf("%d %.2f\n",p[i].id,(float)p[i].g/100.0);
                }

                memset(p,0,sizeof(p));
                for(i=0;i<10005;i++) p[i].id=i;
        }
        return 0;
}
