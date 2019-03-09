#include<algorithm>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct treasure
{
        int w,v;
        float p;
}t[105];
bool cmp(const treasure &a,const treasure &b)
{
        return a.p>b.p;
}
int main()
{
        int V,N;
        int i;
        int ww,vv;
        while(cin>>V)
        {
                if(V==0) break;
                cin>>N;
                for(i=0;i<N;i++)
                {
                        cin>>ww>>vv;
                        t[i].w=ww;
                        t[i].v=vv;
                        t[i].p=(float)ww/(float)vv;
                }
                sort(t,t+N,cmp);
                float sum;
                float ans;
                int next=-1;
                for(i=0;i<N;i++)
                {
                        sum+=(float)t[i].v;
                        ans+=(float)t[i].w;
                        if(sum>V)
                        {
                                sum-=(float)t[i].v;
                                ans-=(float)t[i].w;
                                next=i+1;
                                break;
                        }
                }
                if(next!=-1)
                {
                        float surplus=(float)V-sum;
                        ans+=surplus*t[next].p;
                }
                cout<<ans<<endl;
        }
        return 0;
}
